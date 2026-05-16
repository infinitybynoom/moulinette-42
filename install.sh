#!/bin/bash
# ============================================================
#  Harmoy Moulinette — Installer
#  Tested on: Ubuntu 20.04 / 22.04 / 24.04
# ============================================================

set -e

RED='\033[0;31m'; GREEN='\033[0;32m'; YELLOW='\033[1;33m'
CYAN='\033[0;36m'; BOLD='\033[1m'; NC='\033[0m'

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
check_or_install "binutils" "nm"
check_or_install "valgrind" "valgrind"

echo -e "\n${BOLD}Installing norminette...${NC}"
if command -v norminette &>/dev/null; then
    echo -e "  ${GREEN}[OK]${NC} norminette already installed ($(norminette --version 2>&1 | head -1))"
else
    pip3 install norminette --quiet
    if command -v norminette &>/dev/null; then
        echo -e "  ${GREEN}[OK]${NC} norminette installed"
    else
        PATH_LINE='export PATH="$HOME/.local/bin:$PATH"'
        for rc in "$HOME/.bashrc" "$HOME/.zshrc"; do
            [ -f "$rc" ] || continue
            grep -qF "$PATH_LINE" "$rc" || echo "$PATH_LINE" >> "$rc"
        done
        export PATH="$HOME/.local/bin:$PATH"
        echo -e "  ${GREEN}[OK]${NC} norminette installed (added ~/.local/bin to PATH)"
    fi
fi

echo -e "\n${BOLD}Setting up moulinette command...${NC}"

# Make the moulinette script executable
chmod +x "$MOULINETTE_DIR/moulinette"

# Remove any old alias or symlink that could conflict
for rc in "$HOME/.bashrc" "$HOME/.zshrc"; do
    [ -f "$rc" ] || continue
    if grep -q "alias moulinette=" "$rc"; then
        sed -i '/alias moulinette=/d' "$rc"
        echo -e "  ${YELLOW}[CLEAN]${NC} Removed old alias from $rc"
    fi
done
if [ -L "$HOME/.local/bin/moulinette" ] || [ -f "$HOME/.local/bin/moulinette" ]; then
    rm -f "$HOME/.local/bin/moulinette"
    echo -e "  ${YELLOW}[CLEAN]${NC} Removed old file at ~/.local/bin/moulinette"
fi

# Add moulinette-42 dir to PATH
PATH_LINE="export PATH=\"$MOULINETTE_DIR:\$PATH\""
for rc in "$HOME/.bashrc" "$HOME/.zshrc"; do
    [ -f "$rc" ] || continue
    if grep -q "moulinette-42" "$rc"; then
        sed -i "s|export PATH=.*moulinette-42.*|$PATH_LINE|" "$rc"
        echo -e "  ${GREEN}[OK]${NC} Updated PATH in $rc"
    else
        echo "$PATH_LINE" >> "$rc"
        echo -e "  ${GREEN}[OK]${NC} Added moulinette to PATH in $rc"
    fi
done

echo -e "\n${BOLD}${GREEN}Installation complete!${NC}"
echo ""
echo "  Run this to activate now:"
echo -e "  ${CYAN}source ~/.bashrc${NC}"
echo ""
echo "  Then use from any directory:"
echo "  cd ~/project_piscine42/c01      && moulinette"
echo "  cd ~/project_piscine42/c01/ex03 && moulinette"
echo "  cd ~/project_piscine42          && moulinette all"
echo ""
