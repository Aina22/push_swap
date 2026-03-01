*This project has been created as part of the 42 curriculum by ainaradan, yvoandri.*

# Push_swap

## Description

**Push_swap** is the finall boss in the first circle of the holy graph.
The Goal of this program is sort a **stack a** using a **stack b**.But in the output we only print the **"History"** but not the result **(not the sorted stack a)**.

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
bash
    ./push_swap "all your numbers" 
    ./push_swap all your numbers   # 78 92 56 26 for example
```
#### 2 - With commands
In the program, there are 4 methods to sort the **stack a**.
    -Using the simple algo: (O(n2))
    -Using the medium algo: (O(n√n))
    -Using the complex algo: (O(n log n))
    -Using the adaptative algo:
```
bash
    ./push_swap --simple "all your numbers" 
    ./push_swap --medium all your numbers  # 78 92 56 26 for example
    ./push_swap --complex "all your numbers"
    ./push_swap --adaptive all your numbers
```
#### 3 - Using the bench option
The bench option shows all operations and the numbers of the operations and the disorder.It help the user to visualize the general's purpose.
This is the command for this:
```
bash
    ./push_swap --bench "all your numbers"
     shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.tx) # shuf is a command that give us random numbers for example
```
To save the benchmark in a file you can type this command.
```
bash
    shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.tx) 2> bench.txt
```
To show the containt of the file you can type this command:
```
    cat bench.txt
```

## Resources
* Makefile basics:
  [https://opensource.com/article/18/8/what-how-makefile](https://opensource.com/article/18/8/what-how-makefile)

* Advanced Makefile guide:
  [https://web.stanford.edu/class/archive/cs/cs107/cs107.1174/guide_make.html](https://web.stanford.edu/class/archive/cs/cs107/cs107.1174/guide_make.html)

* For the resource we have to learn radix sort:
  [https://www.geeksforgeeks.org/dsa/radix-sort/](https://www.geeksforgeeks.org/dsa/radix-sort/)

* For more understanding before the developement of our code:
  [https://www.youtube.com/watch?v=OaG81sDEpVk&t=2467s](https://www.youtube.com/watch?v=OaG81sDEpVk&t=2467s)


## Details explanations (technicals explanations)
This is just an example for better understanding.
```
stack a       sorted stack a

| 3 |         | 1 |  
|---|         |---| 
| 2 |   -->   | 2 |  
|---|         |---| 
| 1 |         | 3 |          

```
To achieve this **sorted stack a** we have *11 operations*:
1. **sa** *(swap a)*: Swap the first two elements at the top of stack a.
                    Do nothing if there is only one or no elements.
2. **sb** *(swap b)*: Swap the first two elements at the top of stack b.
                    Do nothing if there is only one or no elements.
3. **ss** : sa and sb at the same time.
4. **pa** *(push a)*: Take the first element at the top of b and put it at the top of a.
                    Do nothing if b is empty.
5. **pb** *(push b)*: Take the first element at the top of a and put it at the top of b.
                    Do nothing if a is empty.
6. **ra** *(rotate a)*: Shift up all elements of stack a by one.
                    The first element becomes the last one.
7. **rb** *(rotate b)*: Shift up all elements of stack b by one.
                    The first element becomes the last one.
8. **rr** : ra and rb at the same time.
9. **rra** *(reverse rotate a)*: Shift down all elements of stack a by one.
        The last element becomes the first one.
10. **rrb** *(reverse rotate b)*: Shift down all elements of stack b by one.
        The last element becomes the first one.
11. **rrr** : rra and rrb at the same time.

### Big O
For this project we hev to implement four algorithms: the simple algorithm with the notation of **O(n2)**, the medium algo with the notation of **O(n√n)**,
the complex algo with the notation of **O(n log n)**,and finally the adapative that sort the stack a using the disorder metric.
#### **O(n2)**
For this algorithm we use **Simple min/max extraction methode**.The approach is to find the minimal value in the stack and compare the minimum value with the rest of the stack.
#### **O(n√n)**
For this algorithm we use **Chunk-based sorting method**.The approach is to divide the stack into **chunks**,allocate an array that has sorted values compare it with the stack a, if the value is smaller than in the allocated array the push to stack b.
#### **O(n log n)**
For this algorithm we use **Radix sort adaptation method**, **Quick sort adaptation with stack partitioning**, and **Binary indexed tree approaches**.
    **Radix sort adaptation** is a method that sort all elements digit by digit.
    **Quick sort adaptation with stack partitioning** is a method that directly sort the stack.
    **Binary indexed tree approaches** is a method that index the binary by one.

## Goal of this Project
* The goal of this project is the discovery of all sorting methods like **Simple min/max extraction methode**, **Chunk-based sorting method**, **Radix sort adaptation method**, **Quick sort adaptation with stack partitioning**, **Binary indexed tree approaches**.
* Learn to handle a real project like **push_swap**(Push_swap is already a litle software application).
