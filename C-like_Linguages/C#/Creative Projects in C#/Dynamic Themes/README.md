ᴄᴏᴅᴇ 👾

---

# CosmoX

## What is it?

A complex C# project implementing a game-like system with multiple components managing events, rendering maps, resources, and core game logic. The main program initializes and starts the game through the `GameManager` class.

## How to use?

1. Make sure you have the [.NET SDK](https://dotnet.microsoft.com/en-us/download) installed.

2. Open a terminal in the project root folder and build the project:

```bash
dotnet build
```

3. Run the game:

dotnet run --project src

4. The game will start running based on the logic inside:

```bash
GameManager.StartGame()
```

## Features

- Modular game components including event system, map renderer, and resource manager
- Game logic encapsulated in GameManager
- ASCII art and symbol assets for visual elements
-Automated build and run scripts included
- Basic unit tests in tests/GameLogicTests.cs

## Folder Structure

```bash
📁 CosmoX/
├── assets/                   # Game assets (ASCII art, symbols)
│   └── ascii_art/
│       ├── events_ascii.txt
│       └── map_symbols.txt
├── build/                    # Build and run scripts
│   ├── build.sh
│   └── run_game.sh
├── src/                      # Source code
│   ├── EventSystem.cs
│   ├── GameManager.cs
│   ├── MapRenderer.cs
│   ├── Program.cs            # Main entry point
│   └── ResourceManager.cs
├── tests/                    # Unit tests
│   └── GameLogicTests.cs
└── README.md                 # Project documentation
```

## Demo

📹 [Watch it run](link)

---

<p align="center">૮ ˙Ⱉ˙ ა learn or perish</p>
