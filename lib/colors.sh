#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
BOLD='\033[1m'
NC='\033[0m'

pass()    { echo -e "  ${GREEN}[PASS]${NC} $1"; }
fail()    { echo -e "  ${RED}[FAIL]${NC} $1"; }
warn()    { echo -e "  ${YELLOW}[WARN]${NC} $1"; }
info()    { echo -e "  ${CYAN}[INFO]${NC} $1"; }
header()  { echo -e "\n${BOLD}${BLUE}=== $1 ===${NC}"; }
section() { echo -e "\n${BOLD}--- $1 ---${NC}"; }
