# 2048 文字版遊戲＿改良版

An revised text-based version of the classic 2048 game implemented in C++. This version extends the traditional 2048 game with additional diagonal movement capabilities and save/load functionality.

## Features

- Traditional 2048 game mechanics
- Extended movement in 8 directions:
  - Up (W)
  - Down (X)
  - Left (A)
  - Right (D)
  - Upper-left (Q)
  - Upper-right (E)
  - Lower-left (Z)
  - Lower-right (C)
- Game state saving and loading
- Score tracking
- File corruption detection and handling
- Cross-platform compatibility (Windows/macOS/Linux)

## Requirements

- C++ compiler (GCC, Clang, or MSVC)
- Terminal/Console that supports ANSI escape codes
- CMake (optional, for building)

### Windows
- MinGW or Visual Studio 2019+ with C++ support
- Windows Terminal (recommended) or CMD

### macOS/Linux
- GCC or Clang
- Terminal emulator

## Building and Running

### On macOS/Linux
```bash
# Clone the repository
git clone https://github.com/bradykuo/2048_text_version_game_revised.git
cd 2048_text_version_game_revised

# Compile
g++ main.cpp game.cpp -o 2048game

# Run
./2048game
```

### On Windows
```bash
# Using MinGW
g++ main.cpp game.cpp -o 2048game.exe

# Run
2048game.exe
```

## Game Controls

- W: Move Up
- X: Move Down
- A: Move Left
- D: Move Right
- Q: Move Upper-left
- E: Move Upper-right
- Z: Move Lower-left
- C: Move Lower-right
- S: Save game
- L: Load game
- ESC or B: Quit game

## Implementation Details

The game is implemented using C++ with Object-Oriented Programming principles:
- `game` class handling core game mechanics
- Custom exception handling for file corruption
- Cross-platform terminal handling

### Project Structure
```
.
├── main.cpp          # Main game loop and UI
├── game.cpp          # Game logic implementation
├── 2048.h           # Game class definition
└── exception.h      # Custom exception classes
```

## Original Assignment Requirements

This game was developed as part of a programming assignment with the following key requirements:
1. Implement the classic 2048 game with additional diagonal movement
2. Include save/load functionality with file corruption handling
3. Use object-oriented programming principles
4. Implement custom exception handling

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is available for academic and educational purposes.
