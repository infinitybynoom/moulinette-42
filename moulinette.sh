#!/bin/bash
# ============================================================
#  Harmoy Moulinette — 42 School Piscine Checker (C00-C13)
# ============================================================
#  Usage:
#    ./moulinette.sh <module> <path_to_submission>
#    ./moulinette.sh c01 ~/piscine/c01
#    ./moulinette.sh c01/ex03 ~/piscine/c01/ex03
#    ./moulinette.sh all ~/piscine/
#
#  Options:
#    --no-norm     Skip norminette check
#    --no-header   Skip 42 header check
#    --leaks       Run valgrind memory leak check
#    --help        Show this help
# ============================================================

set -euo pipefail

_src="${BASH_SOURCE[0]}"
while [ -L "$_src" ]; do _src="$(readlink "$_src")"; done
MOULINETTE_DIR="$(cd "$(dirname "$_src")" && pwd)"
unset _src
TESTS_DIR="$MOULINETTE_DIR/tests"

source "$MOULINETTE_DIR/lib/colors.sh"
source "$MOULINETTE_DIR/lib/header.sh"
source "$MOULINETTE_DIR/lib/norm.sh"
source "$MOULINETTE_DIR/lib/compile.sh"
source "$MOULINETTE_DIR/lib/forbidden.sh"
source "$MOULINETTE_DIR/lib/runner.sh"

OPT_NORM=true
OPT_HEADER=true
OPT_LEAKS=false
TOTAL_PASS=0
TOTAL_FAIL=0
TOTAL_WARN=0

usage() {
    echo "Usage: $0 [options] [module|all] [path]"
    echo ""
    echo "  No args  — auto-detect from current directory name"
    echo "  module   — c00..c13 or 'all'"
    echo "  path     — optional, defaults to current directory"
    echo ""
    echo "Options:"
    echo "  --no-norm     Skip norminette check"
    echo "  --no-header   Skip 42-header check"
    echo "  --leaks       Enable valgrind memory check"
    echo "  --help        Show this help"
    echo ""
    echo "Examples:"
    echo "  cd ~/project_piscine42/c01      && moulinette"
    echo "  cd ~/project_piscine42/c01/ex03 && moulinette"
    echo "  cd ~/project_piscine42          && moulinette all"
    exit 0
}

_detect_from_cwd() {
    local cwd
    cwd="$(pwd)"
    local cur
    cur="$(basename "$cwd")"
    local par
    par="$(basename "$(dirname "$cwd")")"

    if echo "$cur" | grep -qE '^ex[0-9]+$' && echo "$par" | grep -qE '^c[0-9]+$'; then
        MODULE="$par/$cur"
        SUBMISSION_PATH="$cwd"
    elif echo "$cur" | grep -qE '^c[0-9]+$'; then
        MODULE="$cur"
        SUBMISSION_PATH="$cwd"
    else
        echo "Cannot auto-detect module from directory: $cur"
        echo "Run 'moulinette --help' for usage."
        exit 1
    fi
}

parse_args() {
    while [[ $# -gt 0 ]]; do
        case "$1" in
            --no-norm)   OPT_NORM=false; shift ;;
            --no-header) OPT_HEADER=false; shift ;;
            --leaks)     OPT_LEAKS=true; shift ;;
            --help|-h)   usage ;;
            *)           break ;;
        esac
    done
    MODULE="${1:-}"
    SUBMISSION_PATH="${2:-}"

    if [ -z "$MODULE" ]; then
        _detect_from_cwd
        return
    fi

    if [ -z "$SUBMISSION_PATH" ]; then
        if echo "$MODULE" | grep -q '/'; then
            local mod ex
            mod="$(echo "$MODULE" | cut -d'/' -f1)"
            ex="$(echo "$MODULE" | cut -d'/' -f2)"
            SUBMISSION_PATH="$(pwd)/$mod/$ex"
        elif [ "$MODULE" = "all" ]; then
            SUBMISSION_PATH="$(pwd)"
        else
            SUBMISSION_PATH="$(pwd)/$MODULE"
        fi
    fi
}

load_exercise_config() {
    local config="$1"
    FORBIDDEN=""
    FLAGS="-Wall -Wextra -Werror"
    FILES=""
    HAS_ARGS=false
    if [ -f "$config" ]; then
        source "$config"
    fi
}

run_exercise() {
    local module="$1"
    local ex="$2"
    local ex_path="$3"
    local test_dir="$TESTS_DIR/$module/$ex"

    header "$module / $ex"

    if [ ! -d "$ex_path" ]; then
        fail "Submission directory not found: $ex_path"
        TOTAL_FAIL=$((TOTAL_FAIL + 1))
        return 1
    fi

    if [ ! -d "$test_dir" ]; then
        warn "No test found for $module/$ex — skipping"
        TOTAL_WARN=$((TOTAL_WARN + 1))
        return 0
    fi

    load_exercise_config "$test_dir/info.conf"

    local ex_score=0
    local ex_total=0

    # 1. File presence check
    if [ -n "$FILES" ]; then
        section "Required Files"
        for f in $FILES; do
            ex_total=$((ex_total + 1))
            if [ -f "$ex_path/$f" ]; then
                pass "Found: $f"
                ex_score=$((ex_score + 1))
            else
                fail "Missing: $f"
            fi
        done
    fi

    # 2. 42 Header check
    if $OPT_HEADER; then
        ex_total=$((ex_total + 1))
        if check_headers_in_dir "$ex_path"; then
            ex_score=$((ex_score + 1))
        fi
    fi

    # 3. Norminette
    if $OPT_NORM; then
        ex_total=$((ex_total + 1))
        norm_result=0
        check_norminette "$ex_path" || norm_result=$?
        if [ $norm_result -eq 0 ]; then
            ex_score=$((ex_score + 1))
        elif [ $norm_result -eq 2 ]; then
            warn "Norminette skipped (not installed)"
        fi
    fi

    # 4. Forbidden functions
    if [ -n "$FORBIDDEN" ]; then
        ex_total=$((ex_total + 1))
        if check_forbidden_functions "$ex_path" "$FORBIDDEN"; then
            ex_score=$((ex_score + 1))
        fi
    fi

    # 5. Makefile (for c09)
    if [ "$module" = "c09" ]; then
        ex_total=$((ex_total + 1))
        if check_makefile "$ex_path" "$test_dir"; then
            ex_score=$((ex_score + 1))
        fi
        echo ""
        _print_score "$ex" $ex_score $ex_total
        return
    fi

    # 6. Compile + Test
    if [ -f "$test_dir/test.c" ]; then
        ex_total=$((ex_total + 2))
        if compile_exercise "$ex_path" "$test_dir" "$FLAGS"; then
            ex_score=$((ex_score + 1))
            if $HAS_ARGS; then
                if run_tests_args "$ex_path" "$test_dir"; then
                    ex_score=$((ex_score + 1))
                fi
            else
                if run_tests "$ex_path" "$test_dir"; then
                    ex_score=$((ex_score + 1))
                fi
            fi
        fi
    fi

    # 7. Valgrind (optional)
    if $OPT_LEAKS && [ -f "$test_dir/_test_bin" ]; then
        section "Memory Leaks (valgrind)"
        if command -v valgrind &>/dev/null; then
            local vg_out
            vg_out=$(valgrind --leak-check=full --error-exitcode=1 \
                     "$test_dir/_test_bin" 2>&1)
            if [ $? -eq 0 ]; then
                pass "No memory leaks"
            else
                fail "Memory leaks detected"
                echo "$vg_out" | grep -E "(ERROR|definitely|possibly|LEAK)" | \
                    head -10 | sed 's/^/    /'
            fi
        else
            warn "valgrind not installed"
        fi
    fi

    echo ""
    _print_score "$ex" $ex_score $ex_total

    if [ $ex_total -gt 0 ] && [ $((ex_score * 100 / ex_total)) -ge 60 ]; then
        TOTAL_PASS=$((TOTAL_PASS + 1))
    else
        TOTAL_FAIL=$((TOTAL_FAIL + 1))
    fi
}

_print_score() {
    local ex="$1"
    local score="$2"
    local total="$3"
    if [ $total -eq 0 ]; then return; fi
    local pct=$((score * 100 / total))
    if [ $pct -ge 80 ]; then
        echo -e "  ${GREEN}${BOLD}Score $ex: $score/$total ($pct%)${NC}"
    elif [ $pct -ge 50 ]; then
        echo -e "  ${YELLOW}${BOLD}Score $ex: $score/$total ($pct%)${NC}"
    else
        echo -e "  ${RED}${BOLD}Score $ex: $score/$total ($pct%)${NC}"
    fi
}

run_module() {
    local module="$1"
    local submission_base="$2"
    local module_tests="$TESTS_DIR/$module"

    if [ ! -d "$module_tests" ]; then
        warn "No tests for module $module"
        return
    fi

    echo -e "\n${BOLD}${CYAN}╔══════════════════════════════╗${NC}"
    echo -e "${BOLD}${CYAN}║  MODULE: ${module^^}                  ║${NC}"
    echo -e "${BOLD}${CYAN}╚══════════════════════════════╝${NC}"

    for ex_test_dir in "$module_tests"/ex*/; do
        [ -d "$ex_test_dir" ] || continue
        local ex
        ex=$(basename "$ex_test_dir")
        local ex_submission="$submission_base/$ex"
        run_exercise "$module" "$ex" "$ex_submission"
    done
}

print_summary() {
    echo ""
    echo -e "${BOLD}${BLUE}╔══════════════════════════════╗${NC}"
    echo -e "${BOLD}${BLUE}║        FINAL SUMMARY         ║${NC}"
    echo -e "${BOLD}${BLUE}╚══════════════════════════════╝${NC}"
    echo -e "  ${GREEN}Passed exercises : $TOTAL_PASS${NC}"
    echo -e "  ${RED}Failed exercises : $TOTAL_FAIL${NC}"
    echo -e "  ${YELLOW}Warned exercises : $TOTAL_WARN${NC}"
    local total=$((TOTAL_PASS + TOTAL_FAIL))
    if [ $total -gt 0 ]; then
        local pct=$((TOTAL_PASS * 100 / total))
        echo ""
        if [ $pct -ge 70 ]; then
            echo -e "  ${GREEN}${BOLD}Overall: $pct% ($TOTAL_PASS/$total)${NC}"
        else
            echo -e "  ${RED}${BOLD}Overall: $pct% ($TOTAL_PASS/$total)${NC}"
        fi
    fi
    echo ""
}

# ── MAIN ──────────────────────────────────────────────────

parse_args "$@"

if [ -z "$MODULE" ]; then
    usage
fi

SUBMISSION_PATH="$(realpath "$SUBMISSION_PATH" 2>/dev/null || echo "$SUBMISSION_PATH")"

echo -e "${BOLD}${CYAN}"
echo " ╔═══════════════════════════════════════╗"
echo " ║    Harmoy Moulinette  v1.0            ║"
echo " ║    42 School Piscine Checker C00-C13  ║"
echo " ╚═══════════════════════════════════════╝"
echo -e "${NC}"

# Handle "module/ex" shorthand
if echo "$MODULE" | grep -q '/'; then
    mod=$(echo "$MODULE" | cut -d'/' -f1)
    ex=$(echo "$MODULE" | cut -d'/' -f2)
    run_exercise "$mod" "$ex" "$SUBMISSION_PATH"
elif [ "$MODULE" = "all" ]; then
    for mod in c00 c01 c02 c03 c04 c05 c06 c07 c08 c09 c10 c11 c12 c13; do
        if [ -d "$SUBMISSION_PATH/$mod" ]; then
            run_module "$mod" "$SUBMISSION_PATH/$mod"
        fi
    done
else
    run_module "$MODULE" "$SUBMISSION_PATH"
fi

print_summary
