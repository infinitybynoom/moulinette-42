#!/bin/bash

check_norminette() {
    local dir="$1"
    local result=0

    section "Norminette"

    if ! command -v norminette &>/dev/null; then
        warn "norminette not installed. Install: pip3 install norminette"
        return 2
    fi

    # Pass directory directly — avoids *.h glob hanging on stdin when no .h files exist
    local output
    output=$(norminette "$dir" 2>/dev/null) || true
    local exit_code=$?

    if echo "$output" | grep -q "Error"; then
        fail "Norminette errors found:"
        echo "$output" | grep -v "^OK" | while IFS= read -r line; do
            echo "    $line"
        done
        result=1
    else
        pass "Norminette: All files OK"
    fi
    return $result
}
