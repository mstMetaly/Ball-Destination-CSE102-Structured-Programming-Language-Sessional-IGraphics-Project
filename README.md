# Ball Destination Game

A complete maze-based game built with the IGraphics library where players control a ball to reach a destination while avoiding monsters and obstacles.

## 📋 Table of Contents
- [Game Overview](#game-overview)
- [Features](#features)
- [Game Controls](#game-controls)
- [System Requirements](#system-requirements)
- [Installation & Setup](#installation--setup)
- [Compilation Instructions](#compilation-instructions)
- [Game Mechanics](#game-mechanics)
- [Project Structure](#project-structure)

## 🎮 Game Overview

Ball Destination is a challenging maze navigation game where you control a ball through a complex maze while avoiding multiple monsters with different movement patterns. The goal is to reach the destination point while surviving with your limited lives.

## ✨ Features

- **Multi-level Maze Navigation**: Complex maze layouts with walls and obstacles
- **Monster AI**: 5 different monsters with unique movement patterns and behaviors
- **Life System**: Start with 6 lives, lose them when touching monsters or walls
- **Score Tracking**: Earn points based on survival time and performance
- **High Score System**: Persistent scoreboard with player names
- **Multiple Game Pages**: 
  - Home page with game options
  - Main game screen
  - Help and instructions
  - About page
  - High score display
- **Audio Support**: Background music and sound effects
- **Player Customization**: Enter your name for the scoreboard

## 🎯 Game Controls

### In-Game Controls
- **Arrow Keys**: Move the ball (Up, Down, Left, Right)
- **Mouse**: Navigate menus and select options
- **Enter**: Confirm selections in menus

### Menu Navigation
- Click on menu items to navigate between different pages
- Use mouse to select options and start new games

## 💻 System Requirements

- **Operating System:** Windows (tested on Windows 10)
- **Compiler:** GCC/G++ (MinGW recommended)
- **Libraries:** OpenGL, GLUT, GLU, GLAux (included)
- **IDE:** Code::Blocks (project file included) or any C++ IDE

## 🚀 Installation & Setup

### Prerequisites
1. Install MinGW or any GCC compiler
2. Ensure OpenGL libraries are available (included in the repository)

### Quick Start
1. Clone or download this repository
2. Open `IGraphics.cbp` in Code::Blocks
3. Build and run the project

## 🔧 Compilation Instructions

### Using Command Line

**Compilation:**
Command line compiling:
-----------------------
g++ -IOpenGL\include -w -c BallDemo.cpp -o BallDemo.o

Command line linking:
---------------------
g++ -LOpenGL\lib BallDemo.o -o BallDemo.exe -lGlaux -lGLU32 -lglui32 -lglut32 -lOPENGL32 -lgdi32

Command line running:
---------------------
Make sure glut32.dll is present in the same folder
Run BallDemo.exe

**Running:**
- Ensure `glut32.dll` is present in the same folder as the executable
- Run `BallGame.exe`

### Using Code::Blocks
1. Open `IGraphics.cbp`
2. Build and run (F9)

## 🎲 Game Mechanics

### Core Gameplay
- **Objective**: Navigate your ball from the starting position to the destination
- **Movement**: Use arrow keys to move the ball in four directions
- **Collision Detection**: Avoid touching walls and monsters
- **Lives**: You start with 6 lives, lose one when hitting obstacles or monsters

### Monster Behavior
The game features 5 different monsters with unique movement patterns:
- **Monster 1**: Moves in a specific pattern around the maze
- **Monster 2**: Has different movement speed and direction
- **Monster 3**: Follows another movement algorithm
- **Monster 4**: Moves with different timing
- **Monster 5**: Has unique pathfinding behavior

### Scoring System
- Points are awarded based on survival time
- Higher scores for longer survival
- Score is saved with player name
- High score board tracks top performances

### Game States
- **Home Page**: Main menu with game options
- **Game Page**: Active gameplay screen
- **Help Page**: Game instructions and controls
- **About Page**: Game information
- **Instructions Page**: Detailed gameplay guide
- **Scoreboard**: High score display

## 📁 Project Structure

```
Ball Destination Game/
├── BALL DESTINATION PROJECT final.cpp   # Main game source code
├── iGraphics.h                          # Graphics library header
├── IGraphics.cbp                        # Code::Blocks project file
├── OpenGL/                              # OpenGL libraries and headers
│   ├── include/                         # Header files
│   ├── lib/                            # Library files
│   └── dll/                            # DLL files
├── Game Assets/                         # Game resources
│   ├── *.bmp                           # Image files (sprites, backgrounds, UI)
│   ├── game_music.wav                  # Background music
│   ├── maze.txt                        # Maze layout data
│   ├── score.txt                       # Score records
│   └── highscore.txt                   # High score data
└── README.md                           # This file
```

### Key Asset Files
- **Images:** Various BMP files for game sprites, backgrounds, and UI elements
- **Audio:** `game_music.wav` for background music
- **Data:** 
  - `maze.txt` - Maze layout data defining walls and obstacles
  - `score.txt` - Current score records
  - `highscore.txt` - Persistent high score data

## 🎯 Game Tips

1. **Plan Your Route**: Study the maze layout before moving
2. **Watch Monster Patterns**: Each monster has a predictable movement pattern
3. **Use Walls Strategically**: Walls can help you avoid monsters
4. **Don't Rush**: Take your time to plan safe paths
5. **Practice**: The more you play, the better you'll understand monster behaviors

## 🐛 Known Issues

- Music playback may need to be enabled in the code (currently commented out)
- Some systems may require additional OpenGL drivers

## 🤝 Contributing

This is an educational game project. Feel free to:
- Report bugs or issues
- Suggest gameplay improvements
- Add new features or levels
- Enhance the documentation

## 📄 License

This project is intended for educational purposes. Please respect the original authors' work and use responsibly.

---

**Note:** This game is designed for Windows systems. For other platforms, OpenGL libraries may need to be installed separately.

