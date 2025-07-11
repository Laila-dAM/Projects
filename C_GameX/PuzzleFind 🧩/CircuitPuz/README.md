ᴄᴏᴅᴇ 👾

---

# CircuitPuz

## What is it?

A terminal-based puzzle game written in C where the player rearranges components of a digital circuit (like wires and logic gates) to connect the Start `[S]` to the End `[E]`. The player must move pieces across a grid while respecting the circuit rules — think digital Sokoban with logic gates.

## How to play?

1. Make sure you have a C compiler installed (like `gcc`).

2. Open a terminal in the project folder and compile the game:

```bash
gcc circle.c -o circle
```

3. Run the game:

```bash
./circle
```

4. Use the grid coordinates to move components:

```bash
Enter move (x1 y1 x2 y2) or 'q' to quit:
```

Example:

```bash
0 2 1 2
```
Moves the component from row 0, column 2 to row 1, column 2.

## Features

- 5x5 grid logic puzzle
- ASCII representation of logic gates and circuit components
- Interactive CLI movement system
- Humor and reactions for invalid moves (rage table flip included)
- Basic logic gate types: AND (&), OR (|), NOT (!)
- Simple and fun challenge

## Folder Structure

```bash
📁 CircuitPuz/
├── circle/               # (Optional) Assets or variations
├── circle.c              # Main source code
└── README.md             # Project documentation
```

## Demo

📹 [Watch it run](link)

---

<p align="center">૮ ˙Ⱉ˙ ა learn or perish</p>
