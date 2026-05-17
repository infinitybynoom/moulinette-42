# REFERENCE — อ่านก่อนแก้ไขอะไรทุกครั้ง

ไฟล์นี้คือ source of truth สำหรับ moulinette-42
ก่อนแก้ test, info.conf, expected.txt หรือเพิ่ม exercise ใหม่ **ต้องมาอ่านไฟล์นี้ก่อนเสมอ**

---

## โครงสร้างแต่ละ exercise

```
tests/<cXX>/
  <exYY>/
    info.conf      ← FILES= ต้องตรงกับ PDF "Files to turn in" ทุกตัว
    test.c         ← เรียกใช้ function ของนักเรียน + main
    expected.txt   ← output ที่ถูกต้องจาก test.c นั้น
```

---

## FILES to turn in — ครบทุก Subject (จาก PDF)

### C00
| ex | file |
|---|---|
| ex00 | ft_putchar.c |
| ex01 | ft_print_alphabet.c |
| ex02 | ft_print_reverse_alphabet.c |
| ex03 | ft_print_numbers.c |
| ex04 | ft_is_negative.c |
| ex05 | ft_print_comb.c |
| ex06 | ft_print_comb2.c |
| ex07 | ft_putnbr.c |
| ex08 | ft_print_combn.c |

### C01
| ex | file |
|---|---|
| ex00 | ft_ft.c |
| ex01 | ft_ultimate_ft.c |
| ex02 | ft_swap.c |
| ex03 | ft_div_mod.c |
| ex04 | ft_ultimate_div_mod.c |
| ex05 | ft_putstr.c |
| ex06 | ft_strlen.c |
| ex07 | ft_rev_int_tab.c |
| ex08 | ft_sort_int_tab.c |

### C02
| ex | file |
|---|---|
| ex00 | ft_strcpy.c |
| ex01 | ft_strncpy.c |
| ex02 | ft_str_is_alpha.c |
| ex03 | ft_str_is_numeric.c |
| ex04 | ft_str_is_lowercase.c |
| ex05 | ft_str_is_uppercase.c |
| ex06 | ft_str_is_printable.c |
| ex07 | ft_strupcase.c |
| ex08 | ft_strlowcase.c |
| ex09 | ft_strcapitalize.c |
| ex10 | ft_strlcpy.c |
| ex11 | ft_putstr_non_printable.c |
| ex12 | ft_print_memory.c |

### C03
| ex | file |
|---|---|
| ex00 | ft_strcmp.c |
| ex01 | ft_strncmp.c |
| ex02 | ft_strcat.c |
| ex03 | ft_strncat.c |
| ex04 | ft_strstr.c |
| ex05 | ft_strlcat.c |

> ⚠️ c03/ex06 ใน moulinette มี ft_strnstr.c ซึ่งไม่อยู่ใน PDF — ยังไม่ได้ลบ

### C04
| ex | file |
|---|---|
| ex00 | ft_strlen.c |
| ex01 | ft_putstr.c |
| ex02 | ft_putnbr.c |
| ex03 | ft_atoi.c |
| ex04 | ft_putnbr_base.c |
| ex05 | ft_atoi_base.c |

> ⚠️ moulinette มีแค่ ex00–ex03 (ขาด ex04, ex05)

### C05
| ex | file |
|---|---|
| ex00 | ft_iterative_factorial.c |
| ex01 | ft_recursive_factorial.c |
| ex02 | ft_iterative_power.c |
| ex03 | ft_recursive_power.c |
| ex04 | ft_fibonacci.c |
| ex05 | ft_sqrt.c |
| ex06 | ft_is_prime.c |
| ex07 | ft_find_next_prime.c |
| ex08 | ft_ten_queens_puzzle.c |

> ⚠️ moulinette มีแค่ ex00–ex07 (ขาด ex08)

### C06
| ex | file |
|---|---|
| ex00 | ft_print_program_name.c |
| ex01 | ft_print_params.c |
| ex02 | ft_rev_params.c |
| ex03 | ft_sort_params.c |

> ⚠️ moulinette มีแค่ ex00–ex02 (ขาด ex03)

### C07
| ex | file |
|---|---|
| ex00 | ft_strdup.c |
| ex01 | ft_range.c |
| ex02 | ft_ultimate_range.c |
| ex03 | ft_strjoin.c |
| ex04 | ft_convert_base.c, ft_convert_base2.c |
| ex05 | ft_split.c |

> ⚠️ moulinette มีแค่ ex00–ex03 (ขาด ex04, ex05)

### C08
| ex | file |
|---|---|
| ex00 | ft.h |
| ex01 | ft_boolean.h |
| ex02 | ft_abs.h |
| ex03 | ft_point.h |
| ex04 | ft_strs_to_tab.c |
| ex05 | ft_show_tab.c |

> ⚠️ moulinette มีแค่ ex00–ex04 (ขาด ex05)

### C09
| ex | file |
|---|---|
| ex00 | libft_creator.sh, ft_putchar.c, ft_swap.c, ft_putstr.c, ft_strlen.c, ft_strcmp.c |
| ex01 | Makefile |
| ex02 | ft_split.c |

### C10
| ex | file |
|---|---|
| ex00 | Makefile + program files (display_file) |
| ex01 | Makefile + program files (cat) |
| ex02 | Makefile + program files (tail) |
| ex03 | Makefile + program files (hexdump) |

> ⚠️ moulinette มีแค่ ex00–ex02 (ขาด ex03)

### C11
| ex | file |
|---|---|
| ex00 | ft_foreach.c |
| ex01 | ft_map.c |
| ex02 | ft_any.c |
| ex03 | ft_count_if.c |
| ex04 | ft_is_sort.c |
| ex05 | do-op program files |
| ex06 | ft_sort_string_tab.c |
| ex07 | ft_advanced_sort_string_tab.c |

> ⚠️ moulinette มีแค่ ex00–ex04 (ขาด ex05, ex06, ex07)

### C12
| ex | file |
|---|---|
| ex00 | ft_create_elem.c, ft_list.h |
| ex01 | ft_list_push_front.c, ft_list.h |
| ex02 | ft_list_size.c, ft_list.h |
| ex03 | ft_list_last.c, ft_list.h |
| ex04 | ft_list_push_back.c, ft_list.h |
| ex05 | ft_list_push_strs.c, ft_list.h |
| ex06 | ft_list_clear.c, ft_list.h |
| ex07 | ft_list_at.c, ft_list.h |
| ex08 | ft_list_reverse.c |
| ex09 | ft_list_foreach.c, ft_list.h |
| ex10 | ft_list_foreach_if.c, ft_list.h |
| ex11 | ft_list_find.c, ft_list.h |
| ex12 | ft_list_remove_if.c, ft_list.h |
| ex13 | ft_list_merge.c, ft_list.h |
| ex14 | ft_list_sort.c, ft_list.h |
| ex15 | ft_list_reverse_fun.c, ft_list.h |
| ex16 | ft_sorted_list_insert.c, ft_list.h |
| ex17 | ft_sorted_list_merge.c, ft_list.h |

> ⚠️ moulinette มีแค่ ex00–ex09 (ขาด ex10–ex17)
> ft_list.h อยู่ที่ tests/c12/ft_list.h (shared ทุก ex)

### C13
| ex | file |
|---|---|
| ex00 | btree_create_node.c, ft_btree.h |
| ex01 | btree_apply_prefix.c, ft_btree.h |
| ex02 | btree_apply_infix.c, ft_btree.h |
| ex03 | btree_apply_suffix.c, ft_btree.h |
| ex04 | btree_insert_data.c, ft_btree.h |
| ex05 | btree_search_item.c, ft_btree.h |
| ex06 | btree_level_count.c, ft_btree.h |
| ex07 | btree_apply_by_level.c, ft_btree.h |

> ⚠️ moulinette มีแค่ ex00–ex03 (ขาด ex04–ex07)
> ft_btree.h อยู่ที่ tests/c13/ft_btree.h (shared ทุก ex)
> โครงสร้าง: left, right, *item

---

## กฎในการแก้ไข

1. **info.conf** — FILES= ต้องตรงกับตาราง PDF ด้านบนทุกตัว (ชื่อและจำนวน)
2. **test.c** — ต้อง `#include` header ที่ถูกต้อง และเรียก function ที่ตรงกับ exercise นั้น
3. **expected.txt** — ต้องตรงกับ output จริงที่ได้จาก implementation ที่ถูกต้อง
4. **เพิ่ม exercise ใหม่** — ต้องสร้างทั้ง 3 ไฟล์ (info.conf, test.c, expected.txt) และอัพเดตตารางในไฟล์นี้
5. **อย่าลืม** — ถ้า exercise ต้องส่ง header (เช่น ft_btree.h, ft_list.h) ให้วางไว้ที่ root ของ tests/cXX/ และ include ด้วย path สัมพัทธ์ `"../ft_btree.h"`

---

## สิ่งที่ยังขาด (TODO)

| subject | ขาด |
|---|---|
| C03 | ex06 (ft_strnstr.c) — ไม่มีใน PDF ควรลบ |
| C04 | ex04 (ft_putnbr_base.c), ex05 (ft_atoi_base.c) |
| C05 | ex08 (ft_ten_queens_puzzle.c) |
| C06 | ex03 (ft_sort_params.c) |
| C07 | ex04 (ft_convert_base.c + ft_convert_base2.c), ex05 (ft_split.c) |
| C08 | ex05 (ft_show_tab.c) |
| C10 | ex03 (hexdump) |
| C11 | ex05 (do-op), ex06 (ft_sort_string_tab.c), ex07 (ft_advanced_sort_string_tab.c) |
| C12 | ex10–ex17 |
| C13 | ex04–ex07 |
