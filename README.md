# Arrays-vs-Linked-Lists-C-Implementation-
**C99 code implementation to compare arrays versus linked lists with performance instrumentation**

## Overview

This project compares two ways of storing data: arrays and linked lists. Both use the same interface and support basic operations like adding, removing, accessing, and looping through data.

A custom memory library tracks memory usage and operations so the performance of each structure can be compared under the same conditions.

The purpose of the project is to show the differences and trade-offs between arrays, which store data in contiguous memory, and linked lists, which use dynamically connected nodes.

## Features
- Custom implementations of a dynamic array and singly linked list
- Shared interface for consistent operation comparison
- Supports insertion, deletion, traversal, and element access
- Memory instrumentation using a custom tracking library (`mem`)
- Modular multi-file C project structure

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
```bash
git clone https://github.com/rmelocot/Arrays-vs-Linked-Lists-C-Implementation-.git
cd A1
```

### 2. Build the project
```bash
make
```

### 3. Run test program
```bash
LD_LIBRARY_PATH=./lib ./bin/test0
```

### 4. Clean build files
```bash
make clean
make cleaner
```
### Example Output
size&emsp;&emsp;&emsp;   malloc&emsp;&emsp;&emsp;   free&emsp;&emsp;&emsp;   deref<br>
======&emsp; ======&emsp; ======&emsp; ======<br>
...<br>

(Exact output depends on test cases and operations performed.)

## What I Learned
- The main differences between arrays and linked lists
- Arrays are faster for direct access, while linked lists are better for insertions and deletions
- How memory usage differs between the two structures
- How to build a linked list using pointers
- How to create consistent APIs for different data structures

## Challenges & Notes
- Managing memory correctly with the custom memory library
- Debugging pointer logic in the linked list implementation
- Keeping both implementations consistent for accurate comparison
- Understanding how low-level memory operations affect performance

## Academic Context

This project was completed independently as part of a university-level Data Structures and Algorithms course and has been adapted for portfolio purposes.
