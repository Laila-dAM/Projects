# Mindsweeper: Debugging Challenge

Welcome to **Mindsweeper**, a text-based puzzle game where your goal is to uncover all the safe cells in a grid without triggering any errors.

## Features

- **Grid**: 5x5 grid with safe cells (`_`) and error cells (`X`).
- **Adjacent Errors**: Numbers show how many adjacent cells have errors.
- **Recursive Reveal**: Automatically uncover surrounding cells with no errors.
- **Game Over**: Triggering an error ends the game.
- **Winning**: Uncover all safe cells to win.

## How to Play

1. Enter coordinates (row, column) to reveal a cell.
2. Avoid revealing error cells (`X`).
3. Win by uncovering all safe cells.

## Technologies

- **C**: Used for game logic and user input.