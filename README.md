*This project has been created as part of the 42 curriculum by wabin-wa.*

# Push Swap

## Description

Push Swap is a sorting algorithm project from the 42 curriculum. The objective is to sort a list of unique integers in ascending order using only two stacks (`a` and `b`) and a limited set of stack operations.

The main goal is not only to sort the numbers correctly but also to produce the smallest possible number of operations.

## Instructions

### Compile

```bash
make
```

### Run

```bash
./push_swap 2 1 3 6 5 8
```

Example:

```bash
$ ./push_swap 3 2 1
sa
rra
```

Clean the project:

```bash
make clean
make fclean
make re
```

## Algorithm

This project uses the **Turk Algorithm**.

The general approach is:

1. Push most elements from stack `a` to stack `b`.
2. Calculate the cost of moving each element back.
3. Select the move with the lowest cost.
4. Perform combined rotations whenever possible.
5. Push the selected element back to stack `a`.
6. Finish by rotating `a` until the smallest element is on top.

## Additional Information

### Data Structure

- Doubly linked lists are used to represent both stacks.
- Each node stores additional information such as its index, target position, movement cost, and the best rotation method to reduce the total number of operations.

### Error Handling

The program checks for:
- Invalid integers
- Integer overflow
- Duplicate values
- Empty or invalid input

If an error is detected, it prints:

```text
Error
```

to standard error.

## Resources

- Turk Algorithm explanation: https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0
- 42 Push Swap subject

### AI Usage

AI was used to:
- Discuss and design the stack data structure.
- Decide which members should be stored in each node to simplify cost calculation and movement decisions.
- Clarify C language concepts and explain algorithm ideas during development.

All generated ideas were reviewed, understood, tested, and implemented manually.
