# ⚡ Modified Quick Sort

An implementation of an optimized Quick Sort approach in **C++** that combines **median-of-three pivot selection** with **insertion sort for small partitions**.

## ✨ Approach

The implementation uses two ideas to improve practical sorting performance:

1. **Median-of-three pivot selection** — chooses a pivot using the first, middle, and last elements rather than always selecting a fixed position.
2. **Insertion sort for small partitions** — when a partition contains at most 10 elements, insertion sort is used instead of continuing the recursive Quick Sort process.

## 🧠 Complexity

- Average Quick Sort: **O(n log n)**
- Worst case: **O(n²)**
- Small partitions use insertion sort to reduce recursive overhead.

## 🚀 Run

Compile with a C++ compiler:

```bash
g++ main.cpp -o quicksort
./quicksort
```

The included example array is sorted and printed to the console.

## 🎯 Project Status

Completed algorithm-learning project.

## 👨‍💻 Author

**Dreamjain** — [GitHub](https://github.com/Dreamjain)
