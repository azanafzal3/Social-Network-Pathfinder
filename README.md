
# CS-2009 Design and Analysis of Algorithms (Fall 2024)
## Social Network Analysis Project

**National University of Computer and Emerging Sciences**  
**School of Computing - Islamabad Campus**  
**Deadline: Monday, 9th December 2024 (2:25 PM)**  

---

## 👥 Group Members
- **Name 1**: Muhammad Azan Afzal  
  **Roll Number**: 22I-1741  

---

## 📁 Project Structure

```
📦 22I-1741_22I-XXXX/
 ┣ 📄 part1.cpp
 ┣ 📄 part2.cpp
 ┣ 📄 report.pdf
 ┣ 📄 README.md
```

---

## 📌 Problem Statement

This project involves social network analysis using graph algorithms. The dataset contains user-to-user connections and influence scores.

### ➤ Part 1: Graph-Based Shortest Path
- **Objective**: Build an undirected weighted graph where:
  - **Nodes** = Users
  - **Edges** = Connection between users
  - **Weight** = Distance (lower weight = stronger connection)
- **Algorithms Implemented**:
  - ✅ Dijkstra's Algorithm
  - ✅ A* Algorithm (**Bonus**): Uses heuristic `h(n)` = number of direct neighbors.

### ➤ Part 2: Dynamic Programming on Graph
- **Objective**: Find the longest increasing path based on user influence scores.
- **Approach**:
  - Uses topological sorting and memoization.
  - Influence score of each user must be **strictly increasing** in the sequence.
- **Output**:
  - Maximum length of such chain.
  - Full sequence of users in the longest increasing path.

---

## 🗂 Dataset

Download and place the dataset files in the same directory before execution.

- **Social Graph File**:  
  [`social_network_data.txt`](https://drive.google.com/file/d/1SAcWvOR4cTwOrE_JHto3jHLfeJE3fkV2/view?usp=sharing)
  - Format: `User1 User2 Weight`

- **Influence Scores File**:  
  Place your `influences.txt` file accordingly.  
  - Format: `User InfluenceScore`

---

## ⚙️ Compilation & Execution

### Part 1: Dijkstra / A*
```bash
g++ part1.cpp -o part1
./part1
```

### Part 2: Dynamic Programming on Graph
```bash
g++ part2.cpp -o part2
./part2
```

> Ensure your dataset files are placed in the working directory.

---

## 📊 Report Summary

- **PDF Report**: Contains
  - Pseudocode for both parts.
  - Asymptotic time complexity analysis.
  - Graph explanation and DP approach.
- Strictly typed (no handwritten content).

---

## ✅ Submission Checklist

- [x] Source code files (`.cpp`) for both parts.
- [x] PDF Report with pseudocode and complexity.
- [x] README file.
- [x] File naming convention: `22I-1741_22I-XXXX.zip`
- [x] Dataset placed in correct location before run.

---

## 📎 Notes

- Implemented in **C++ only**.
- A* algorithm provides a bonus.
- Code is optimized and follows clean structure.
- No late submission will be accepted.

---

### ✨ Happy Coding!
