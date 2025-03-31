# Push_swap

Push_swap is a sorting algorithm project from 42 that focuses on efficiently sorting a stack of numbers using a limited set of operations. The project consists of two main parts:
- An algorithm that sorts a stack using only 8 predefined instructions.
- A checker that verifies if a given sequence of operations successfully sorts the stack.

## Features

### Sorting Algorithm
The sorting algorithm must arrange numbers in ascending order using the following stack operations:
- `sa` (swap top two elements of stack A)
- `sb` (swap top two elements of stack B)
- `ss` (swap top two elements of both stacks)
- `pa` (push top element from stack B to stack A)
- `pb` (push top element from stack A to stack B)
- `ra` (rotate stack A upwards)
- `rb` (rotate stack B upwards)
- `rr` (rotate both stacks upwards)
- `rra` (reverse rotate stack A downwards)
- `rrb` (reverse rotate stack B downwards)
- `rrr` (reverse rotate both stacks downwards)

### Checker Program
The checker reads the output of the push_swap program and determines if the list is correctly sorted. If the operations are valid and successfully sort the list, it outputs `OK`; otherwise, it outputs `KO`.

## Goal
The challenge is to implement an efficient sorting algorithm that minimizes the number of operations, making it both functional and optimized.

## License
This project is developed as part of my education at 42 and follows the school's policies regarding open-source sharing.

## Contact
For any questions or suggestions, feel free to open an issue or reach out!

