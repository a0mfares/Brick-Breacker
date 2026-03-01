# Brick Breaker

A classic Brick Breaker game implemented in C++ using the CMUgraphicsLib library. This project features a complete level design mode, assorted block types, and various power-ups and power-downs to enhance gameplay.

## 🎮 Game Modes

The game operates in two primary modes:
- **Design Mode (`MODE_DSIGN`)**: Allows the user to build and design custom levels. You can add normal bricks, hard bricks, and rocks, as well as save or load level designs.
- **Play Mode (`MODE_PLAY`)**: The main gameplay mode where you control the paddle to bounce the ball and break the bricks.

## ✨ Features

- **Custom Level Designer**: Build your own levels using the built-in toolbar.
- **Multiple Brick Types**:
  - Normal Bricks: Break with a single hit.
  - Hard Bricks: Require multiple hits to break.
  - Rocks: Unbreakable obstacles.
- **Power-Ups**:
  - 🔥 **FireBall**: Enhances the ball's breaking power.
  - 💨 **WindGlide**: Affects movement.
  - ↔️ **WidePaddle**: Increases the paddle's width for easier deflection.
  - 🧲 **Magnet**: Catches the ball on the paddle.
  - 🎱 **MultipleBalls**: Spawns additional balls on the screen.
- **Power-Downs**:
  - 🔄 **ReverseDirection**: Reverses the paddle's movement controls.
  - ⏳ **QuickSand**: Decreases ball/paddle speed.
  - \>\< **ShrinkPaddle**: Decreases the paddle's width.
- **Save & Load Functionality**: Save your custom grid layouts and load them seamlessly using the toolbar options.
- **Score & Lives Tracking**: Keep track of your progress as you break bricks and collect items.

## 🛠️ Tech Stack & Architecture

- **Language**: C++
- **Graphics Library**: `CMUgraphicsLib`
- **External Dependencies**: `libXL` (for Excel-based level loading/saving).
- **Architecture Base**: Object-Oriented Programming (OOP) design.
  - `game`: The main controller coordinating all game entities.
  - `grid`: Manages the matrix of bricks.
  - `collidable`: Base class for objects that can crash into each other (`Ball`, `Paddle`, `brick`).
  - `collectable`: Base class for falling power-ups and power-downs.
  - `toolbar` & `toolbarIcon`: UI components for game controls and level editing.

## 🕹️ Controls

- **Mouse Clicks**: Use the mouse to interact with the toolbar (Add Bricks, Play, Pause, Save, Load, Exit).
- **Keyboard**: Use the keyboard to move the paddle left and right during gameplay.

## 🚀 Getting Started

1. Open the `.sln` or `.vcxproj` file in Microsoft Visual Studio.
2. Ensure `libXL.dll` and `CMUgraphicsLib` dependencies are properly linked in your build environment.
3. Build and run the project (`main.cpp` serves as the entry point).

---
Enjoy playing and creating your own Brick Breaker levels!
