#!/bin/bash

run_tests() {
    local ex_dir="$1"
    local test_dir="$2"
    local binary="$test_dir/_test_bin"
    local result=0

    section "Test Cases"

    if [ ! -f "$binary" ]; then
        warn "Binary not found — skipping tests"
        return 1
    fi

    local expected_file="$test_dir/expected.txt"
    if [ ! -f "$expected_file" ]; then
        warn "No expected.txt — skipping output comparison"
        return 0
    fi

    local actual
    actual=$(timeout 5 "$binary" 2>&1)
    local exit_code=$?

    if [ $exit_code -eq 124 ]; then
        fail "Test TIMEOUT (5s limit — possible infinite loop)"
        return 1
    fi

    local expected
    expected=$(cat "$expected_file")

    if [ "$actual" = "$expected" ]; then
        pass "Output matches expected"
    else
        fail "Output mismatch:"
        echo -e "    ${YELLOW}Expected:${NC}"
        echo "$expected" | head -20 | sed 's/^/      /'
        echo -e "    ${RED}Got:${NC}"
        echo "$actual" | head -20 | sed 's/^/      /'
        result=1
    fi

    rm -f "$binary"
    return $result
}

run_tests_args() {
    local ex_dir="$1"
    local test_dir="$2"
    local binary="$test_dir/_test_bin"

    section "Test Cases (with args)"

    if [ ! -f "$binary" ]; then
        warn "Binary not found — skipping tests"
        return 1
    fi

    local args_file="$test_dir/args_cases.txt"
    if [ ! -f "$args_file" ]; then
        warn "No args_cases.txt — skipping"
        return 0
    fi

    local result=0
    local test_num=1

    while IFS='|' read -r args expected; do
        [ -z "$args" ] && [ -z "$expected" ] && continue
        local actual
        local expected_decoded
        expected_decoded="$(printf '%b' "$expected")"
        actual=$(cd "$test_dir" && timeout 5 "$binary" $args 2>&1)
        if [ "$actual" = "$expected_decoded" ]; then
            pass "Test $test_num: OK (args: $args)"
        else
            fail "Test $test_num FAILED (args: $args)"
            echo "    Expected: $(echo "$expected_decoded" | head -3 | tr '\n' '|')"
            echo "    Got:      $(echo "$actual" | head -3 | tr '\n' '|')"
            result=1
        fi
        test_num=$((test_num + 1))
    done < "$args_file"

    rm -f "$binary"
    return $result
}

check_makefile() {
    local ex_dir="$1"
    local test_dir="$2"
    local result=0

    section "Makefile Check"

    if [ ! -f "$ex_dir/Makefile" ]; then
        fail "No Makefile found"
        return 1
    fi

    cd "$ex_dir" || return 1

    local make_out
    make_out=$(make 2>&1)
    if [ $? -ne 0 ]; then
        fail "make failed:"
        echo "$make_out" | sed 's/^/    /'
        result=1
    else
        pass "make OK"
    fi

    make_out=$(make clean 2>&1)
    if make fclean &>/dev/null; then
        pass "make fclean OK"
    fi

    if make re &>/dev/null; then
        pass "make re OK"
    fi

    cd - > /dev/null
    return $result
}
