This activity has been created as part of the 42 curriculum by Ketlina Rusha and Emanuela Fetau.

**Description**
**Overview**
- **Project:** push_swap — sort integers using two stacks and a limited set of operations.
- **Language:** C
- **Goal:** Produce a sequence of stack operations that sorts the input with as few moves as possible.


**Instructions**

**Repository Layout**
- **Source:** `*.c` files implement the algorithm and stack operations.
- **Header:** [push_swap.h](push_swap.h) declares types and functions.
- **Build:** [Makefile](Makefile) builds the `push_swap` and `checker` binaries.
- **Scripts:** `push_swap_test_linux.sh` — quick test runner for Linux.

**Build**
1. Build the project:

make            # builds push_swap with -Wall -Wextra -Werror
make clean      # removes object files
make fclean     # removes objects and binary
make re         # full rebuild

2. Binaries produced:
- `push_swap` — the main program that prints the operations to sort the input.
- `checker` / `checker_linux` — verifies an operation sequence sorts the input.

**Usage**
- Run `push_swap` with a space-separated list of integers:

```
./push_swap 3 2 5 1 4
```

- Validate an operations list with `checker`:

```
./push_swap 3 2 5 1 4 | ./checker 3 2 5 1 4
```

**Tests & Style**
- Run the provided quick test script:

```
bash ./push_swap_test_linux.sh
```

- Code style is validated with `norminette`.

**Notes**
- The algorithm implements targeted moves between two stacks (`a` and `b`) and optimizes rotations.
- Key files: [turk_move.c](turk_move.c), [turk_sort.c](turk_sort.c), [turk_cost.c](turk_cost.c).

**Resources & How AI Was Used**
-References: stack-based sorting, radix sort, chunk partitioning and double linked lists through online tutorials or Wikipedia and strategy usage medium.com articles.
-AI usage: AI was used for checking purposes, especialy to make sure there were no conflicts on function callings.
