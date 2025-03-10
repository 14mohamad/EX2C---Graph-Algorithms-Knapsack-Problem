# Graph Algorithms & Knapsack Problem
#אלגוריתמים על גרפים ובעיית תרמיל הגב

## Overview
This project includes two main problems implemented in **C**:
1. **Graph Representation & Shortest Path** – A program that reads an adjacency matrix representation of a graph and performs operations such as:
   - Checking for a path between two nodes.
   - Finding the shortest path using **Floyd-Warshall** or **Dijkstra's algorithm**.
2. **Knapsack Problem** – A program that determines the optimal selection of items to maximize value while staying within a weight limit.

## Features
### Graph Algorithms (`my_graph.c`)
- **Reads an adjacency matrix** from user input.
- **Finds shortest paths** between nodes.
- **Determines connectivity** between nodes.
- **Uses Floyd-Warshall Algorithm** for all-pairs shortest paths.
- **Handles directed and undirected graphs**.

### Knapsack Problem (`my_Knapsack.c`)
- **Implements a dynamic programming solution** to the **0/1 Knapsack Problem**.
- **Maximizes item value** while staying within the given weight limit.
- **Outputs the selected items** and their total value.

## Project Structure
- **`Makefile`** – Compiles the programs.
- **`my_mat.h` & `my_mat.c`** – Handles matrix operations for graph algorithms.
- **`my_graph.c`** – Implements shortest path algorithms.
- **`my_Knapsack.c`** – Implements the knapsack optimization algorithm.

## Compilation & Execution
To compile:
```sh
make
