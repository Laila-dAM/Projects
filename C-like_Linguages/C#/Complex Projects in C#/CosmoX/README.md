ᴄᴏᴅᴇ 👾

---

# CosmoX 

## What is it?

CosmoX is a cross‑platform C# console adventure game that lets you explore a procedurally‑generated galaxy rendered entirely in ASCII art.
Under the hood it uses an event‑driven architecture, a lightweight resource manager, and a modular map renderer to deliver an old‑school, terminal‑only experience.

## How to play?

1. Install the [.NET SDK](https://dotnet.microsoft.com/en-us/download) (version 8.0 or later).

2. Open a terminal at the project root and build:

```bash
dotnet build
```

3. Launch the game:

```bash
dotnet run --project src
```
or, on Unix‑like systems, use the helper script:

```bash
./build/run_game.sh
```

## Features

- **ASCII Map Renderer –** draws planets, nebulas, and stations using customizable symbols.
- **Event System –** random or scripted events (pirate attacks, distress calls, anomalies) keep every play‑through unique.
- **Resource Manager –** handles energy, hull integrity, crew morale, and supplies; choices matter.
- **Unit Tests –** core logic covered by xUnit tests in the tests/ folder.
- **Portable Build Scripts –** build.sh and run_game.sh for quick builds on Linux/macOS; Windows supported via dotnet CLI.
- **Zero Dependencies –** pure C# / .NET 8 console app, no external libraries required.

## Folder Structure

```bash
📁 CosmoX/
├── assets/
│   └── ascii_art/
│       ├── events_ascii.txt      # ASCII frames used by the event system
│       └── map_symbols.txt       # Glyph palette for the map renderer
├── build/
│   ├── build.sh                  # Unix helper to build the game
│   └── run_game.sh               # Unix helper to run the game
├── src/
│   ├── EventSystem.cs            # Handles in‑game events
│   ├── GameManager.cs            # Game loop & high‑level orchestration
│   ├── MapRenderer.cs            # Draws the star map
│   ├── ResourceManager.cs        # Manages player resources
│   └── Program.cs                # Entry point
├── tests/
│   └── GameLogicTests.cs         # xUnit tests
└── README.md                     # You are here
```

## Demo

📹 [Watch it run](https://drive.google.com/file/d/1UApslKY_sNPV2AdLipbvlp9ySJUN5ChI/view?usp=sharing)

---

<p align="center">૮ ˙Ⱉ˙ ა learn or perish</p>
