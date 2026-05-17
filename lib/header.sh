#!/bin/bash

check_42_header() {
    local file="$1"
    local first_line
    first_line=$(head -1 "$file" 2>/dev/null)
    if echo "$first_line" | grep -q '^\*\{3,\}' || echo "$first_line" | grep -q '^/\* \*\{3\}'; then
        pass "Header 42 found: $(basename "$file")"
        return 0
    else
        fail "No 42 header in: $(basename "$file")"
        return 1
    fi
}

check_headers_in_dir() {
    local dir="$1"
    local result=0
    section "Checking 42 School Headers"
    if [ -n "$FILES" ]; then
        for _f in $FILES; do
            [ -f "$dir/$_f" ] || continue
            check_42_header "$dir/$_f" || result=1
        done
    else
        for f in "$dir"/*.c "$dir"/*.h; do
            [ -f "$f" ] || continue
            check_42_header "$f" || result=1
        done
    fi
    return $result
}
