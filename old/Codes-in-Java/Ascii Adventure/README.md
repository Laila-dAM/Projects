ᴄᴏᴅᴇ 👾

---

# Ascii Adventure

## What is it?

A Java console game where players interact with an ASCII-based narrative by making choices that shape the story. It uses external text files for dynamic dialog, actions, and even cute kaomojis. All interactions happen through a simple CLI.

## How to play?

1. Make sure you have the [Java JDK](https://www.oracle.com/java/technologies/javase-downloads.html) installed.

2. Open a terminal in the project root and compile all source files:

```bash
javac -d out src/*.java
```

3. Run the simulation:

```bash
java -cp out Main
```

4. Follow the on-screen instructions to dive into the adventure!

## Features

- Interactive text-based story with multiple outcomes
- Loads story, actions, and kaomojis from external resource files
- Simple character system with health points
- Modular and expandable code structure
- Console-based with no external libraries required

## Folder Structure

```bash
📁 Ascii Adventure/
├── src/                      # Java source code
│   ├── Main.java             # Entry point
│   ├── Game.java             # Core game logic
│   ├── Story.java            # Handles story flow
│   ├── Character.java        # Player data
│   ├── Dialog.java           # Dialog system
│   ├── Action.java           # Player choices
│   └── Kaomoji.java          # Adds expression with kaomojis
├── resources/                # External text data
│   ├── story.txt             # Story events
│   ├── actions.txt           # Possible choices
│   └── kaomojis.txt          # ASCII expressions
└── README.md                 # Project documentation
```

## Demo

📹 [Watch it run](link)

---

<p align="center">૮ ˙Ⱉ˙ ა learn or perish</p>
