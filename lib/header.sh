#!/bin/bash

check_42_header() {
    local file="$1"
    local first_line
    first_line=$(head -1 "$file" 2>/dev/null)
    if echo "$first_line" | grep -q '^\*\{3,\}' || echo "$first_line" | grep -q '^/\* \*\{3\}'; then
        pass "Header 42 found: $file"
        return 0
    else
        fail "No 42 header in: $file"
        return 1
    fi
}

check_headers_in_dir() {
    local dir="$1"
    local result=0
    section "Checking 42 School Headers"
    for f in "$dir"/*.c "$dir"/*.h 2>/dev/null; do
        [ -f "$f" ] || continue
        check_42_header "$f" || result=1
    done
    return $result
}
