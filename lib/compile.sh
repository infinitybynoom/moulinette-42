#!/bin/bash

compile_exercise() {
    local ex_dir="$1"
    local test_dir="$2"
    local flags="${3:--Wall -Wextra -Werror}"
    local result=0

    section "Compilation"

    local src_files
    src_files=$(find "$ex_dir" -maxdepth 1 -name "*.c" 2>/dev/null | tr '\n' ' ')

    if [ -z "$src_files" ]; then
        fail "No .c files found in $ex_dir"
        return 1
    fi

    local test_main="$test_dir/test.c"
    local out_bin="$test_dir/_test_bin"

    local compile_out
    compile_out=$(cc $flags -I"$ex_dir" -I"$test_dir" $src_files "$test_main" -o "$out_bin" 2>&1)
    local exit_code=$?

    if [ $exit_code -eq 0 ]; then
        pass "Compilation OK"
    else
        fail "Compilation FAILED:"
        echo "$compile_out" | while IFS= read -r line; do
            echo "    $line"
        done
        result=1
    fi
    return $result
}

compile_no_main() {
    local ex_dir="$1"
    local flags="${2:--Wall -Wextra -Werror}"

    section "Compilation (no main)"

    local src_files
    src_files=$(find "$ex_dir" -maxdepth 1 -name "*.c" 2>/dev/null | tr '\n' ' ')

    if [ -z "$src_files" ]; then
        fail "No .c files found"
        return 1
    fi

    local out_bin="$ex_dir/_obj_test"
    local compile_out
    compile_out=$(cc $flags -I"$ex_dir" -c $src_files 2>&1)
    local exit_code=$?

    if [ $exit_code -eq 0 ]; then
        pass "Compilation OK"
        rm -f ./*.o
    else
        fail "Compilation FAILED:"
        echo "$compile_out" | while IFS= read -r line; do
            echo "    $line"
        done
        return 1
    fi
}
