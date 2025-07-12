ᴄᴏᴅᴇ 👾

---

# PackmanGame

## What is it?

A Java ASCII-based Pac-Man-style console game where the player navigates a map, avoids ghosts, and collects fruits to score points. The game reads the map from a text file and handles all logic using custom game objects like Player, Ghost, and Fruit.

## How to play?

1. Make sure you have the [Java JDK](https://www.oracle.com/java/technologies/javase-downloads.html) installed.

2. Open a terminal in the project folder and compile the project:

```bash
javac -d out src/*.java
```

3. Run the application:

```bash
java -cp out Game
```

4. The game will load the map from assets/gameMap.txt and start in the terminal. Use the specified controls (defined in the game logic) to move and interact.

## Features

- ASCII map loaded from external file
- Player movement and fruit collection
- Ghost enemies with basic AI behavior
- Modular code with separate classes for Game, Player, Ghost, Fruit, and utility logic
- Simple console-based interface for retro-style gameplay

## Folder Structure

```bash
📁 PackmanGame/
├── assets/
│   └── gameMap.txt         # Map layout in plain text
├── src/
│   ├── Game.java           # Main entry point
│   ├── GameUtils.java      # Game initialization and control
│   ├── Player.java         # Player behavior
│   ├── Ghost.java          # Enemy logic
│   ├── Fruit.java          # Points and items
├── README.md               # Project documentation
```

## Demo

📹 [Watch it run](link)

---

<p align="center">૮ ˙Ⱉ˙ ა learn or perish</p>
