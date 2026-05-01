# Arrays-vs-Linked-Lists-C-Implementation-
**C99 implementation comparing arrays and linked lists with performance instrumentation**

## Overview

This project implements both an array-based structure and a linked list using a consistent interface to explore their differences in behavior and efficiency.

Each data structure supports common operations such as insertion, deletion, traversal, and access. A custom memory library is used to track allocations, deallocations, and dereferencing operations, allowing direct comparison of how each structure performs under the same workload.

The goal of this project is to demonstrate the trade-offs between contiguous memory (arrays) and dynamic node-based structures (linked lists).

## Features
- Custom implementation of: dynamic array structure, singly linked list
- Shared interface for fair comparison of operations
- Operations supported: Insert (push / append), Delete (pop / truncate), Traverse and access
- Instrumentation using a memory tracking library (mem)
- Modular multi-file C design with separate libraries

## Tech Stack
Language: C (C99)<br>
Compiler: clang<br>
Build Tools: Make, GNU/Linux toolchain

## Project Structure
A1/ <br>
├── src/<br>
│   &emsp;├── array.c<br>
│   &emsp;├── array.h<br>
│   &emsp;├── list.c<br>
│   &emsp;├── list.h<br>
│   &emsp;└── mem.c / mem.h   # provided memory tracking library<br>
├── Makefile<br>
└── README.md<br>

## Installation & Usage
### 1. Clone the repository
git clone https://github.com/rmelocot/Arrays-vs-Linked-Lists-C-Implementation-.git<br>
cd A1
### 2. Build the project
make
### 3. Run test program
LD_LIBRARY_PATH=./lib ./bin/test0
### 4. Clean build files
make clean      # removes object files<br>
make cleaner    # removes all generated files
### Example Output
size&emsp;&emsp;&emsp;   malloc&emsp;&emsp;&emsp;   free&emsp;&emsp;&emsp;   deref<br>
======&emsp; ======&emsp; ======&emsp; ======<br>
...<br>

(Exact output depends on test cases and operations performed.)

## What I Learned
- Key differences between arrays and linked lists:
- Arrays provide fast indexed access but require shifting elements
- Linked lists allow efficient insertion/removal but require traversal
- How memory allocation patterns differ between the two structures
- How to implement a linked list from scratch using pointers (via an abstracted memory system)
- How to design consistent APIs across different data structures
- Building and linking multiple shared libraries in C
- Using instrumentation to analyze performance behavior beyond Big-O theory

## Challenges & Notes
- Managing memory correctly using the custom mem library required careful tracking of allocations and frees
- Debugging linked list pointer logic (especially append and truncate operations) was error-prone
- Ensuring both implementations followed the exact same interface for fair comparison
- Understanding how low-level memory operations translate into performance differences

## Academic Context

This project was completed as part of a university-level Data Structures and Algorithms course. It has been adapted and documented for portfolio purposes.

## Disclosure

I completed this assignment entirely on my own.
