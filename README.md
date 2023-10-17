# Maze Solver

This project is a C++ program that aims to find a path through a maze from a starting point to a destination. The maze is represented as a binary matrix where 0s represent accessible cells, and 1s represent obstacles. The rat, initially positioned at (0,0), can move up, down, left, and right, but not diagonally, to navigate through the maze and reach the destination at (N-1, M-1).

## Example

Consider the following maze:

| 0 | 1 | 1 | 1 | 1 |
|---|---|---|---|---|
| 0 | 0 | 0 | 0 | 1 |
| 1 | 1 | 1 | 0 | 1 |
| 1 | 1 | 1 | 0 | 0 |
| 1 | 1 | 1 | 1 | 0 |

In this example, the maze is a 5x5 matrix. The accessible cells are represented as 0s, and obstacles as 1s. The path taken by the rat to go from the source (0,0) to the destination (4,4) is marked with grey color.
