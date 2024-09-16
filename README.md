# N Queens Puzzle

*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.*

*Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.*

*Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.*


The solution is coded in C programming language using an algorithm called **back tracking**. The solution uses one global integer array to keep track of row positions where queens could be placed without conflict issue of same column or diagnol. If the n queens are not placed the algorithm tracks all the way back to first index and try an alternative path.


To compile this C program
`gcc main.c -o main.exe`

To execute the compiled program
`.\main.exe`