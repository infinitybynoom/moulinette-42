#!/bin/bash

check_norminette() {
    local dir="$1"
    local result=0

    section "Norminette"

    if ! command -v norminette &>/dev/null; then
        warn "norminette not installed. Install: pip3 install norminette"
        return 2
    fi

    local output
    output=$(norminette "$dir"/*.c "$dir"/*.h 2>/dev/null)
    local exit_code=$?

    if [ $exit_code -eq 0 ]; then
        pass "Norminette: All files OK"
    else
        fail "Norminette errors found:"
        echo "$output" | grep -v "^OK" | while IFS= read -r line; do
            echo "    $line"
        done
        result=1
    fi
    return $result
}
