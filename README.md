*This project has been created as part of the 42 curriculum by thfern.*

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum.
The goal is to sort a stack of integers using a limited set of operations and the smallest possible number of moves.

The project is divided into two parts:

* **push_swap**: receives a list of integers and outputs a sequence of instructions that sorts them.
* **checker** (bonus): reads a list of instructions from standard input and checks whether they correctly sort the stack.

Only two stacks are allowed (`A` and `B`), and only a specific set of operations can be used (swap, push, rotate, reverse rotate).

This project focuses on:

* Algorithmic thinking
* Data structures
* Memory management in C

---

## Instructions

### Compilation

To compile the mandatory part:

```bash
make
```

This will generate the executable:

```bash
./push_swap
```

To compile the bonus (checker):

```bash
make bonus
```

This will generate:

```bash
./checker
```

To clean object files:

```bash
make clean
```

To remove all binaries and objects:

```bash
make fclean
```

To recompile everything:

```bash
make re
```

---

### Usage

#### push_swap

```bash
./push_swap 3 2 1
```

Output example:

```text
sa
rra
```

#### checker

You can test the output of `push_swap` using a pipe:

```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

Expected output:

```text
OK
```

If the stack is not correctly sorted, the checker will output:

```text
KO
```

---

## Resources

### Algorithm and project references

* 42 Subject PDF — *push_swap*
* [https://medium.com/@ayogun/push-swap-c1f5d2d41e97](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

### AI usage

AI tools were used during the development of this project to:

* Assist with debugging runtime errors (segmentation faults, invalid free)
* Help structure and validate the Makefile
* Organization of this README

All algorithmic decisions, implementations, and final code were written and validated by the author.

---

## Notes

* The project follows the Norm of 42.
* Error handling is implemented for invalid input, duplicates, and integer overflows.
* The checker strictly follows the project specifications: it validates both sorting order and that stack B is empty.
