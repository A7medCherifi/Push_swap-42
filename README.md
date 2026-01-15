*This project has been created as part of the 42 curriculum by Acherifi *

## Description

Push_swap is a 42 school project that sorts data in a stack using a limited set of instructions, aiming to achieve the lowest possible number of actions. To succeed, it uses various algorithm that optimized for data sorting.

- **push_swap**:  Takes a list of integers as arguments and outputs the smallest list of operations needed to sort them
- **checker**: Verifies if the given operations correctly sort the stack

### Allowed Operations

- `sa` *(swap a)*: Swap the first 2 elements at the top of stack a.
- `sb` *(swap b)*: Swap the first 2 elements at the top of stack b.
- `ss` : sa and sb at the same time.
- `pa` *(push a)*: Take the first element at the top of b and put it at the top of a.
- `pb` *(push b)*: Take the first element at the top of a and put it at the top of b.
- `ra` *(rotate a)*: Shift up all elements of stack a by 1, The first element becomes the last one.
- `rb` *(rotate b)*: Shift up all elements of stack b by 1, The first element becomes the last one.
- `rr` : ra and rb at the same time.
- `rra` *(reverse rotate a)*: Shift down all elements of stack a by 1, The last element becomes the first one.
- `rrb` *(reverse rotate b)*: Shift down all elements of stack b by 1, The last element becomes the first one.
- `rrr` : rra and rrb at the same time.

## Instructions

### Compilation

Use the provided Makefile to compile the project:

```bash
# Compile push_swap
make

# Compile checker (bonus)
make bonus

# Clean object files
make clean

# Clean everything (objects + executables)
make fclean

# Recompile everything
make re
```

### Usage

#### Push_swap
```bash
# Basic usage
./push_swap 3 2 1 5 4

# Using quoted arguments
./push_swap "3 2 1 5 4"

# Mixed format
./push_swap 3 "2 1" 5 4
```

#### Checker
```bash
# Pipe push_swap output to checker
./push_swap 3 2 1 | ./checker 3 2 1

# Manual input (type operations, then Ctrl+D)
./checker 3 2 1
sa
pb
pa
^D
```

### Expected Output

#### Push_swap
- Outputs the list of operations (one per line)
- Exits with status 0 for valid input
- Prints "Error" and exits with status 1 for invalid input

#### Checker  
- Prints "OK" if stack is sorted correctly
- Prints "KO" if stack is not sorted or operations are invalid
- Prints "Error" for invalid input

### Error Cases

Both programs handle these error cases:
- Non-integer arguments
- Integer overflow (outside INT_MIN to INT_MAX range)
- Duplicate numbers

## Testing

### Performance Benchmark Tests

```bash
# Test with 3 numbers (should use ≤ 3 operations)
ARG="2 1 0"; ./push_swap $ARG | wc -l

# Test with 5 numbers (should use ≤ 12 operations for max points)
ARG="1 5 2 4 3"; ./push_swap $ARG | wc -l

# Test with 100 numbers (should use ≤ 700 operations for max points)
ARG="$(seq 1 100 | sort -R | xargs)"; ./push_swap $ARG | wc -l

# Test with 500 numbers (should use ≤ 5500 operations for max points)
ARG="$(seq 1 500 | sort -R | xargs)"; ./push_swap $ARG | wc -l

# Test correctness
ARG="4 67 +003 87 23"; ./push_swap $ARG | ./checker $ARG
```

### Error Testing

```bash
# Test error handling
./push_swap "1 2 3 2"  
./push_swap "1 2 abc"  
./push_swap "1 2 abc" " "  
./push_swap "   "  
./push_swap ""  
./push_swap 1 2 "" 3 4 
./push_swap 1 2 0000000000000002 3 
./push_swap 1 2 4 -+5 
./push_swap 1 2 "1" 4 
./push_swap "214748364748385 28 47 29"
```

## Algorithm Overview

There is many [Algorithms](https://www.geeksforgeeks.org/dsa/sorting-algorithms/) you can use for sorting, for me i did use optimised [Turk Algorithm](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0) and i will break it down to you:

1. **Small stacks (≤3 elements)**: Direct sorting with minimal operations
2. **Large stacks (>3 elements)**:
	- Set indexes for each element on stack A,
	- get the median by taking the (size of A) / 2,
	- push all elements to stack B except the last 3 elements,
		- when pushing check if the element > median do rotate b `rb`,
		- else nothing.
	- sort the stack A with minimal operations,
	- set the position of all elements on each stack,
	- get the median of each stack,
	- set the target of each element on stack B:
		- look for the "small biggest" index on stack A and set it as the target of element B (ex: stack A(1, 3, 4), stack B(2, 5, 6)).
		in this case the target of 2 is gonna be 3. why? cause 3 and 4 both bigger than 2 but 3 is smaller than 4, so this called "small biggest".
		- if there is not "small biggest" the index on stack B is bigger than all indexes on stack A, than the target of index B will be the smallest index on stack A.
		- set the cost A and cost B for each element in B:
			- you already have the target so you gonna count how many moves you need to reach the top on both stacks, the element on B and the target of it on A.
		- after you set for all elements on stack B a target and cost A and cost B you gonna do (cost A + cost B) and see how many moves that each element need for both ways, and you gonna look for element that needs minimal moves.
	- after setting the element that needs minimal moves you push it to A and set it above of it's target.
	- and do the same again set the positions of each stack and so on.

## Resources

### Documentation & Articles
- [Push_swap Subject PDF](https://cdn.intra.42.fr/pdf/pdf/189070/en.subject.pdf)
- [Push_swap guide](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap/building-the-thing)
- [Push_swap Tutorial](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Turk algorithm explained](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)

## AI Usage

- *Concept details understanding*: I used AI to explain more in details the confusing mechanism of the algorithm. 
- *Testing Strategy*: Generating comprehensive test cases from the user input into the memory leak.
- *Code Optimization Suggestions*: suggesting more efficient sorting approches and code structure imporovements.
- *Helping me to make this beautiful README file*: helping me by giving a structure of this README file.

