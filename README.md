# ♛ Interactive-N-Queens-Solver (C++)

An interactive console-based **N-Queens Puzzle Game and Solver** built using C++.  
It allows users to manually play the puzzle or automatically solve it using backtracking with visualization.

---

<img src="https://www.researchgate.net/publication/362012663/figure/fig3/AS:1177948522577920@1657856221050/N-Queen-problem-explanation-with-8-queens-in-a-chessboard-of-88-On-the-left-is-a-valid.ppm" height="300px" />

## 🎯 Overview

The N-Queens problem is a classic algorithmic challenge where N queens must be placed on an N×N chessboard such that no two queens attack each other.

This project provides:
- Interactive gameplay mode
- Full backtracking solver
- Animated solution visualization
- Complete solution generator

---

## 🎮 Features

- 🧩 Interactive chessboard (console UI)
- ✍️ Manual queen placement & removal
- ⚡ Real-time move validation
- 🤖 Automatic solver (Backtracking)
- 🎬 Animated solution visualization
- 📊 Generate all possible solutions
- 🏆 Win/Lose detection based on user input

---

## 🧩 Game Rules
- ♟️ You must place exactly N queens on an N×N chessboard
- 🚫 No two queens can attack each other
   A queen can attack in:
- Horizontal direction (row)
- Vertical direction (column)
- Diagonal directions (both left and right)
- 🧠 Each row must contain exactly one queen
- 🎯 Each column must contain exactly one queen
- ⚡ Diagonal conflicts are not allowed
- 🏆 The goal is to find a safe configuration of all N queens

## 🧠 Algorithms Used

- Backtracking (Recursive DFS)
- Constraint Checking
  - Row constraints
  - Column constraints
  - Diagonal constraints
- Complete Search (O(N!))
- State tracking using vectors

---

## ⌨️ Commands (Interactive Mode)
