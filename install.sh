#!/bin/bash
# ============================================================
#  Harmoy Moulinette — Installer (no sudo required)
#  Tested on: Ubuntu 20.04 / 22.04 / 24.04 / 42 School
# ============================================================

RED='\033[0;31m'; GREEN='\033[0;32m'; YELLOW='\033[1;33m'
CYAN='\033[0;36m'; BOLD='\033[1m'; NC='\033[0m'

MOULINETTE_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

echo -e "${BOLD}${CYAN}"
echo " ╔═══════════════════════════════════════╗"
echo " ║  Harmoy Moulinette Installer          ║"
echo " ╚═══════════════════════════════════════╝"
echo -e "${NC}"

check_tool() {
    local name="$1"
    local cmd="${2:-$1}"
    if command -v "$cmd" &>/dev/null; then
        echo -e "  ${GREEN}[OK]${NC} $name"
    else
        echo -e "  ${YELLOW}[WARN]${NC} $name not found (install manually if needed)"
    fi
}

echo -e "\n${BOLD}Checking tools...${NC}"
check_tool "gcc"
check_tool "cc (clang/gcc)" "cc"
check_tool "nm (binutils)" "nm"
check_tool "valgrind"
check_tool "python3"
check_tool "pip3"

echo -e "\n${BOLD}Installing norminette (no sudo)...${NC}"
if command -v norminette &>/dev/null; then
    echo -e "  ${GREEN}[OK]${NC} norminette already installed ($(norminette --version 2>&1 | head -1))"
else
    if command -v pip3 &>/dev/null; then
        pip3 install norminette --user --quiet
        export PATH="$HOME/.local/bin:$PATH"
        if command -v norminette &>/dev/null; then
            echo -e "  ${GREEN}[OK]${NC} norminette installed"
        else
            echo -e "  ${YELLOW}[WARN]${NC} norminette installed but not in PATH yet (will be added below)"
        fi
    else
        echo -e "  ${YELLOW}[WARN]${NC} pip3 not found — cannot install norminette"
        echo -e "         Run: ${CYAN}pip3 install norminette --user${NC}"
    fi
fi

echo -e "\n${BOLD}Setting up moulinette command...${NC}"

chmod +x "$MOULINETTE_DIR/moulinette"

# Remove any old alias or file that could conflict
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

# Add moulinette-42 dir and ~/.local/bin to PATH
for rc in "$HOME/.bashrc" "$HOME/.zshrc"; do
    [ -f "$rc" ] || continue

    # moulinette-42 path
    PATH_LINE="export PATH=\"$MOULINETTE_DIR:\$PATH\""
    if grep -q "moulinette-42" "$rc"; then
        sed -i "s|export PATH=.*moulinette-42.*|$PATH_LINE|" "$rc"
        echo -e "  ${GREEN}[OK]${NC} Updated moulinette PATH in $rc"
    else
        echo "$PATH_LINE" >> "$rc"
        echo -e "  ${GREEN}[OK]${NC} Added moulinette to PATH in $rc"
    fi

    # ~/.local/bin for norminette
    LOCAL_BIN='export PATH="$HOME/.local/bin:$PATH"'
    if ! grep -qF '.local/bin' "$rc"; then
        echo "$LOCAL_BIN" >> "$rc"
        echo -e "  ${GREEN}[OK]${NC} Added ~/.local/bin to PATH in $rc"
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
