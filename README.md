# Harmoy Moulinette — 42 School Piscine Checker

Automated grader for **42 School C Piscine**, covering **C00 to C13**.  
Mimics the real Moulinette: norminette, compilation, forbidden functions, and test output.

---

## What it checks (per exercise)

| Step | Check | Detail |
|------|-------|--------|
| 1 | **Required files** | Are all expected `.c`/`.h` files present? |
| 2 | **42 Header** | Does each file start with the `/* ****` header? |
| 3 | **Norminette** | Does code pass `norminette` (style checker)? |
| 4 | **Forbidden functions** | Are disallowed functions used? (via `nm`) |
| 5 | **Compilation** | Does it compile with `cc -Wall -Wextra -Werror`? |
| 6 | **Test output** | Does output match expected exactly? |
| 7 | **Valgrind** (opt) | Any memory leaks? (`--leaks` flag) |

---

## Installation (Ubuntu)

```bash
git clone https://github.com/infinitybynoom/moulinette-42.git
cd moulinette-42
bash install.sh
source ~/.bashrc
```

**What `install.sh` does:**
- Installs `gcc`, `clang`, `nm` (binutils), `valgrind`
- Installs `norminette` via `pip3`
- Creates a `moulinette` symlink in `~/.local/bin`

---

## Usage

**`cd` เข้า folder แล้วรัน `moulinette` เลย — ไม่ต้องพิมพ์อะไรเพิ่ม:**

```bash
# อยู่ใน module folder → ตรวจทุก exercise
cd ~/project_piscine42/c01
moulinette

# อยู่ใน exercise folder → ตรวจ exercise เดียว
cd ~/project_piscine42/c01/ex03
moulinette

# อยู่ใน piscine root → ตรวจทุก module
cd ~/project_piscine42
moulinette all
```

**หรือระบุเองก็ได้:**

```bash
moulinette c01           # ตรวจ c01 ใน current dir
moulinette c01/ex03      # ตรวจ exercise เดียว
moulinette c01 ~/project_piscine42/c01   # explicit path
```

**Options:**

```bash
moulinette --no-norm     # ข้าม norminette
moulinette --no-header   # ข้าม 42 header check
moulinette --leaks       # เปิด valgrind memory check
moulinette --help        # แสดง help
```

---

## Example Output

```
 ╔═══════════════════════════════════════╗
 ║    Harmoy Moulinette  v1.0            ║
 ║    42 School Piscine Checker C00-C13  ║
 ╚═══════════════════════════════════════╝

╔══════════════════════════════╗
║  MODULE: C01                 ║
╚══════════════════════════════╝

=== c01 / ex00 ===

--- Required Files ---
  [PASS] Found: ft_ft.c

--- Checking 42 School Headers ---
  [PASS] Header 42 found: ft_ft.c

--- Norminette ---
  [PASS] Norminette: All files OK

--- Compilation ---
  [PASS] Compilation OK

--- Test Cases ---
  [PASS] Output matches expected

  Score ex00: 5/5 (100%)

╔══════════════════════════════╗
║        FINAL SUMMARY         ║
╚══════════════════════════════╝
  Passed exercises : 8
  Failed exercises : 1
  Warned exercises : 0

  Overall: 88% (8/9)
```

---

## Module Coverage

| Module | Topic | Exercises |
|--------|-------|-----------|
| C00 | Basic output with `write()` | ex00–ex08 |
| C01 | Pointers | ex00–ex08 |
| C02 | String manipulation | ex00–ex12 |
| C03 | String comparison / concat | ex00–ex06 |
| C04 | Number conversions | ex00–ex03 |
| C05 | Recursion | ex00–ex07 |
| C06 | argc / argv | ex00–ex02 |
| C07 | Memory allocation (`malloc`) | ex00–ex03 |
| C08 | Header files (macros) | ex00–ex04 |
| C09 | Makefiles | ex00–ex02 |
| C10 | File I/O | ex00–ex02 |
| C11 | Function pointers | ex00–ex04 |
| C12 | Linked lists | ex00–ex09 |
| C13 | Advanced linked list ops | ex00–ex03 |

---

## How the Moulinette Works

### 1. Norminette check

Runs the official `norminette` tool from 42 School (Python package).

```bash
norminette <submission_dir>/*.c *.h
```

Norminette enforces:
- Max **80 characters** per line
- Max **25 lines** per function
- Max **5 functions** per `.c` file  
- **tab indentation** (not spaces)
- **snake_case** for variable/function names
- Mandatory **42 header** at top of each file
- No trailing whitespace

### 2. Forbidden function detection

Uses `nm` (symbol table tool) to list symbols referenced by the compiled object file.  
If a forbidden function appears as `U symbol` (Undefined — meaning it's called externally), it fails.

```bash
cc -c student_file.c -o tmp.o
nm tmp.o | grep " U printf"   # would catch forbidden printf
```

### 3. Compilation test

Compiles student code together with a test `main()`:

```bash
cc -Wall -Wextra -Werror \
   -I<submission_dir> \
   <student_files.c> tests/c01/ex00/test.c \
   -o _test_bin
```

A compilation error means **0 points** for that exercise (real Moulinette behaviour).

### 4. Output comparison

Runs the compiled binary and compares stdout to `expected.txt` exactly.  
A 5-second timeout catches infinite loops.

```bash
timeout 5 ./_test_bin > actual.txt
diff actual.txt expected.txt
```

### 5. Score calculation

Each exercise gets a score (checks passed / total checks).  
≥ 60% = PASS, < 60% = FAIL.  
Final summary shows total passed/failed across all exercises.

---

## Submission structure expected

```
~/piscine/
├── c00/
│   ├── ex00/ft_putchar.c
│   ├── ex01/ft_print_alphabet.c
│   └── ...
├── c01/
│   ├── ex00/ft_ft.c
│   └── ...
└── ...
```

---

## Adding custom tests

Each exercise test lives in `tests/<module>/<exercise>/`:

```
tests/c01/ex00/
├── info.conf      # FILES, FORBIDDEN, FLAGS
├── test.c         # test main()
└── expected.txt   # expected stdout
```

`info.conf` format:
```bash
FILES="ft_ft.c"          # required file names (space separated)
FORBIDDEN=""             # forbidden functions (space separated)
FLAGS="-Wall -Wextra -Werror"
HAS_ARGS=false           # true if test uses args_cases.txt
```

---

## Requirements (Ubuntu)

- Ubuntu 20.04 / 22.04 / 24.04
- `gcc` / `clang` (cc)
- `python3` + `pip3`
- `norminette` (installed by `install.sh`)
- `nm` (from `binutils`)
- `valgrind` (optional, for `--leaks`)

---

## License

MIT — free to use, share, modify.
