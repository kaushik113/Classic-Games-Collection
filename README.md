# Classic Games Collection

This repository is a collection of classic games including Sudoku Solver, Connect 4, and Tic-Tac-Toe. Each game is implemented in C++ and designed to be fun, educational, and easy to run.

## Sudoku Solver

The Sudoku Solver is a C++ program that solves Sudoku puzzles by finding a valid arrangement of numbers that satisfies the rules of the game. Sudoku is a logic-based, combinatorial number-placement puzzle. The objective is to fill a 9x9 grid with digits so that each column, each row, and each of the nine 3x3 subgrids contain all of the digits from 1 to 9.

### Features

- **Board Representation:** The board is represented using a 2D character array, where each element represents a cell on the board. An empty cell is represented by `'.'`.
- **Board Visualization:** The board is printed with different colors for initial values and the filled values. Initial values are shown in green, and filled values are shown in red.
- **Validation:** The `canFill` function checks if a number can be placed in a specific cell without violating the Sudoku rules.
- **Backtracking Algorithm:** The `Sudoku` function uses a backtracking algorithm to solve the puzzle by recursively filling empty cells with valid values and backtracking when necessary.
- **Customizable Puzzles:** The program will solve the predefined Sudoku puzzle in the code. You can modify the `board` variable in the `main` function to solve different puzzles.


## Tic-Tac-Toe Game

The Tic-Tac-Toe game is a classic two-player game implemented in C++. Players take turns placing their respective marks ('X' or 'O') on a 4x4 grid. The objective is to be the first to form a horizontal, vertical, or diagonal line of your mark.

### Features

- **Board Representation:** The board is represented using a 2D character array, where each element represents a cell on the board. An empty cell is represented by `'.'`.
- **Board Visualization:** The `printBoard` function displays the current state of the board. Each player's moves are displayed with their respective marks ('X' in red and 'O' in green). Empty cells are represented by `'.'`.
- **Validation:** The `isValidMove` function checks if a move is valid by ensuring the selected cell is within bounds and not already occupied.
- **Gameplay Mechanics:** Players alternate turns, with 'X' starting the game. The `makeMove` function allows each player to place their mark on an empty cell on the board.
- **Winning Condition:** The `hasWon` function checks if either player has formed a winning line horizontally, vertically, or diagonally.
- **End Game Conditions:** The game ends when a player wins, the board is full resulting in a draw, or when a player makes an invalid move.
