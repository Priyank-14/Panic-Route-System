# 🚨 Panic Route System

### Risk-Aware Pathfinding using Modified Dijkstra Algorithm

---

## 📌 Overview

The **Panic Route System** is a Data Structures and Algorithms (DSA) project implemented in C that computes the **safest route** between locations by incorporating **risk (danger levels)** into pathfinding.

Unlike traditional shortest-path systems, this project prioritizes **safety over distance**, making it suitable for real-world scenarios like emergency evacuation and secure navigation.

---

## 🎯 Objective

To design a system that:

* Models a city as a **graph**
* Assigns both **distance and danger levels** to roads
* Computes the **safest path using a modified Dijkstra algorithm**

---

## 🧠 Core Idea

Instead of minimizing distance alone, we redefine the cost function:

Cost = Distance + (Danger × Weight)

| Parameter | Meaning              |
| --------- | -------------------- |
| Distance  | Length of the path   |
| Danger    | Risk level (0–10)    |
| Weight    | Importance of safety |

---

## ⚙️ Key Features

* 📍 Graph representation using **Adjacency List**
* 🚧 Each edge stores **distance + danger**
* 🧮 **Modified Dijkstra Algorithm**
* ⚡ **Min Heap (Priority Queue)** for optimization
* 🧠 Dynamic **risk-weight adjustment**
* 📊 Menu-driven interface
* ⚠️ Input validation
* 📖 Clear result interpretation

---

## 🏗️ Data Structures Used

* Graph (Adjacency List)
* Linked List (Edge representation)
* Min Heap (Priority Queue)
* Arrays (`dist[]`, `visited[]`, `parent[]`)

---

## 🔄 Algorithm

### 🔹 Traditional Dijkstra

* Minimizes **distance only**

### 🔹 Modified Dijkstra (This Project)

* Minimizes **risk-adjusted cost**

Cost = Distance + (Danger × Weight)

✔ Safer paths may be chosen even if longer

---

## ⚡ Time Complexity

| Version              | Complexity |
| -------------------- | ---------- |
| Traditional Dijkstra | O(V²)      |
| Heap-based Dijkstra  | O(E log V) |

✔ Modification does not affect complexity

---

## 📂 Project Structure

panic-route-system/
│
├── src/
│   ├── main.c
│   ├── graph.c
│   ├── heap.c
│   ├── dijkstra.c
│   ├── risk.c
│
├── include/
│   ├── graph.h
│   ├── heap.h
│   ├── dijkstra.h
│   ├── risk.h
│
├── input/
│   └── sample.txt
│
├── docs/
│   └── Project_Report.pptx
│
├── README.md
└── .gitignore

---

## ▶️ How to Run

### 🔹 Compile

gcc src/*.c -o panic

### 🔹 Run

./panic

---

## 🧪 Sample Input

4
4
0 1 2 9
1 2 2 9
0 2 6 1
2 3 3 2

---

## 🧠 Sample Output

✔ SAFEST PATH: 0 → 2 → 3
✔ TOTAL COST: 15

---

## 📊 Result Insight

* Shortest path is **not always safest**
* System avoids **high-risk edges**
* Provides a **balanced decision between safety and distance**

---

## 🚀 Applications

* Emergency evacuation systems
* Disaster management
* Military route planning
* Smart navigation systems

---

## 🔥 Innovation

This project extends classical Dijkstra by:

* Introducing a **risk-aware cost function**
* Enabling **dynamic safety prioritization**
* Simulating **real-world decision-making**

---

## 🎓 Learning Outcomes

* Graph representation using adjacency list
* Heap-based optimization
* Algorithm design and modification
* Real-world application of DSA

---

## 🏆 Key Insight

> We did not change Dijkstra’s algorithm — we changed what it optimizes.

---

## 👨‍💻 Author

**Priyank Sinha**
B.Tech CSE | UPES
