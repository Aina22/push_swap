*This project has been created as part of the 42 curriculum by ainaradan[, yvoandri].*

# Push_swap

## Description

**Push_swap** is the finall boss in the first circle of the holy graph.
The Goal of this program is sort a **stack A** using a **stack B**.But in the output we only print the **"History"** but not the result **(not the sorted stack A)**.

## Instructions

### Project structure
```
push_swap/
├── libft/
├── bench.c
├── bench.h
├── bench_utils.c
├── bench_utils1.c
├── bench_utils2.c
│
├── checker.c
├── checker.h
├── checker_push.c
├── checker_swap.c
├── checker_rotation.c
├── checker_rotate_reverse.c
├── checker_read_line.c
├── checker_utils.c
│
├── common_utils.c
├── compute_disorder.c
├── calcul_end_index.c
│
├── ft_simple_algo.c
├── ft_medium_algo.c
├── ft_medium_algo_utilities.c
├── ft_complex_algo.c
├── ft_complex_algo_utilities.c
├── ft_adaptive_algo.c
│
├── ft_push.c
├── ft_swap.c
├── ft_rotation.c
├── ft_ra.c
│
├── hashset.c
├── hashset.h
├── hashset_utils.c
│
├── main.c
├── main_utils.c
├── move_checker.c
│
├── number_parser.c
├── parsing.c
├── parsing_utils.c
├── validation.c
│
├── stack_in_order.c
├── general_utils.c
├── push_swap_utilities.c
│
├── push_swap.h
├── Makefile
├── README.md
```

### 1 - Clone the repository

First, download the project using `git clone`:

### 2 - Compile the project

To compile the project you must type: `make`.

### 3 - Makefile rules

* `make`       → compile the project
* `make clean` → remove object files
* `make fclean`→ remove object files + and the compiled ./push_swap
* `make re`    → full rebuild

---
After the project has compliled.You can choose all of the command in the terminal.
#### 1 - The simplest
```
    ./push_swap "all your numbers" 
    ./push_swap all your numbers  //78 92 56 26 for example
```
#### 2 - With commands
In the program, there are 3 methods to sort the **stack A**.
    -Using the simple algo: (O(n2))
    -Using the medium algo: (O(n√n))
    -Using the complex algo: (O(n log n))
```
    ./push_swap --simple "all your numbers" 
    ./push_swap --medium all your numbers  //78 92 56 26 for example
    ./push_swap --complex "all your numbers"
    ./push_swap --adaptive "all your numbers"
```
#### 3 - Using 
