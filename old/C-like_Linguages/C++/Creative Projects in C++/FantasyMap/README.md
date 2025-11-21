ᴄᴏᴅᴇ 👾

---

# Fantasy Map Creator 

## What is it?

A C++ graphical application using SFML that randomly generates a fantasy map with different map elements — Cities, Rivers, Mountains, and Forests. It visualizes the map in a window and exports the map data to a JSON file for further use.

## How to play?

1. Make sure you have SFML installed on your system.  
   For Debian/Ubuntu, you can install it via:

```bash
sudo apt install libsfml-dev
```

2. Open a terminal in the project folder and compile the program with:

```bash
g++ map.cxx -o map -lsfml-graphics -lsfml-window -lsfml-system
```

3. Run the application:

```bash
./map
```

4. A window will open displaying the randomly generated map elements:
Red circles: Cities

- **Blue circles:** Rivers
- **Black circles:** Mountains
- **Green circles:** Forests

5. Close the window to end the program. A file named fantasy_map.json will be created containing the map data.

## Features

- Generates 20 random map elements with positions on an 800x600 window
- Visualizes each element with colored circles in an SFML window
- Exports the map to a JSON file describing each element’s type and position
- Simple and extendable code base for building fantasy map applications

## Folder Structure

```bash
📁 FantasyMap/
├── fantasy_map.json       # Exported map data in JSON format
├── map                    # Compiled executable (after build)
├── map.cxx                # Main C++ source code
└── README.md              # Project documentation
```

---

<p align="center">૮ ˙Ⱉ˙ ა learn or perish</p>
