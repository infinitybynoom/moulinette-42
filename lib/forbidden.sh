#!/bin/bash

check_forbidden_functions() {
    local ex_dir="$1"
    local forbidden_list="$2"
    local result=0

    section "Forbidden Functions"

    if [ -z "$forbidden_list" ]; then
        info "No forbidden functions defined for this exercise"
        return 0
    fi

    local obj_file
    obj_file=$(mktemp /tmp/moulinette_XXXXXX.o)

    local src_files
    src_files=$(find "$ex_dir" -maxdepth 1 -name "*.c" 2>/dev/null | tr '\n' ' ')

    cc -c -I"$ex_dir" $src_files -o "$obj_file" 2>/dev/null

    if [ ! -f "$obj_file" ]; then
        warn "Could not compile for forbidden check"
        return 1
    fi

    local found_forbidden=0
    for func in $forbidden_list; do
        if nm "$obj_file" 2>/dev/null | grep -q " U ${func}$\| U _${func}$"; then
            fail "Forbidden function used: $func"
            found_forbidden=1
            result=1
        fi
    done

    if [ $found_forbidden -eq 0 ]; then
        pass "No forbidden functions used"
    fi

    rm -f "$obj_file"
    return $result
}
