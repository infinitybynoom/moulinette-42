#!/bin/bash
# ============================================================
#  Harmoy Moulinette — Installer
#  Tested on: Ubuntu 20.04 / 22.04 / 24.04
# ============================================================

set -e

RED='\033[0;31m'; GREEN='\033[0;32m'; YELLOW='\033[1;33m'
CYAN='\033[0;36m'; BOLD='\033[1m'; NC='\033[0m'

INSTALL_DIR="$HOME/.local/bin"
MOULINETTE_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

echo -e "${BOLD}${CYAN}"
echo " ╔═══════════════════════════════════════╗"
echo " ║  Harmoy Moulinette Installer          ║"
echo " ╚═══════════════════════════════════════╝"
echo -e "${NC}"

check_or_install() {
    local pkg="$1"
    local cmd="${2:-$1}"
    if command -v "$cmd" &>/dev/null; then
        echo -e "  ${GREEN}[OK]${NC} $pkg already installed"
    else
        echo -e "  ${YELLOW}[INSTALL]${NC} Installing $pkg..."
        sudo apt-get install -y "$pkg" -q
        echo -e "  ${GREEN}[OK]${NC} $pkg installed"
    fi
}

echo -e "\n${BOLD}Checking dependencies...${NC}"
sudo apt-get update -q

check_or_install "gcc" "gcc"
check_or_install "clang" "cc"
check_or_install "python3" "python3"
check_or_install "python3-pip" "pip3"
check_or_install "nm (binutils)" "nm"
check_or_install "valgrind" "valgrind"

echo -e "\n${BOLD}Installing norminette...${NC}"
if command -v norminette &>/dev/null; then
    echo -e "  ${GREEN}[OK]${NC} norminette already installed ($(norminette --version 2>&1 | head -1))"
else
    pip3 install norminette --quiet
    if command -v norminette &>/dev/null; then
        echo -e "  ${GREEN}[OK]${NC} norminette installed"
    else
        echo -e "  ${YELLOW}[WARN]${NC} norminette not in PATH — add ~/.local/bin to PATH"
        echo 'export PATH="$HOME/.local/bin:$PATH"' >> "$HOME/.bashrc"
        export PATH="$HOME/.local/bin:$PATH"
    fi
fi

echo -e "\n${BOLD}Setting up moulinette command...${NC}"
mkdir -p "$INSTALL_DIR"
chmod +x "$MOULINETTE_DIR/moulinette.sh"

if [ ! -f "$INSTALL_DIR/moulinette" ] || [ "$MOULINETTE_DIR/moulinette.sh" -nt "$INSTALL_DIR/moulinette" ]; then
    ln -sf "$MOULINETTE_DIR/moulinette.sh" "$INSTALL_DIR/moulinette"
    echo -e "  ${GREEN}[OK]${NC} Symlink created: $INSTALL_DIR/moulinette"
fi

if ! echo "$PATH" | grep -q "$INSTALL_DIR"; then
    echo 'export PATH="$HOME/.local/bin:$PATH"' >> "$HOME/.bashrc"
    echo -e "  ${YELLOW}[INFO]${NC} Added $INSTALL_DIR to PATH in ~/.bashrc"
    echo -e "  ${YELLOW}[INFO]${NC} Run: source ~/.bashrc"
fi

echo -e "\n${BOLD}${GREEN}Installation complete!${NC}"
echo ""
echo "  Usage:   moulinette <module> <path>"
echo "  Example: moulinette c01 ~/piscine/c01"
echo "  Example: moulinette all ~/piscine"
echo ""
echo "  Or run directly:"
echo "  $MOULINETTE_DIR/moulinette.sh c01 ~/piscine/c01"
echo ""
