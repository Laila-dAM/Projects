ᴄᴏᴅᴇ 👾

---

# Mindsweeper

## What is it?

A terminal puzzle game written in C that challenges you to "debug" a hidden board full of fatal errors. Inspired by Minesweeper, you must reveal all safe cells without triggering a bug. If you step on one... it's game over.

## How to play?

1. Compile the main C file:

```bash
gcc mindsweeper -o mindsweeper
```

2. Run the game in your terminal:

```bash
./mindsweeper
```

3. The game will display a hidden grid. On each turn:
- Enter the row and column of the cell you want to reveal (e.g., 2 3).
- Try to avoid fatal bugs (X) and uncover all safe areas (_).
- If you trigger an error, the program ends with a failure message.
- Reveal everything safely to win and “debug the system”.

# Features
- Classic Minesweeper logic in pure C
- Randomized board with hidden “bugs”
- Auto-reveal of safe adjacent cells
- Minimalist CLI interface
- Instant win/loss feedback

## Folder Structure

```bash
📁 Mindsweeper/
├── mindsweeper         # Compiled game (after build)
├── Patch.c             # Optional patch file (not required to run)
├── pat.mp4             # Game demo video
└── README.md           # Project documentation
```

## Demo

📹 [Watch it run](https://drive.google.com/file/d/1fUrrl1HI2iZOPORLjYFghQEDerIngyVb/view?usp=sharing)

---

<p align="center">૮ ˙Ⱉ˙ ა learn or perish</p>
