# Plurality Electoral Linear Search Algorithms

A robust C-language implementation of the classic **Plurality (First-Past-The-Post)** voting system. This project focuses on structured data types, dynamic command-line inputs, and deterministic search boundaries.

## 📐 Algorithmic Framework & Logic

In a plurality voting system, every voter casts one vote for their preferred candidate, and the candidate with the highest absolute tally wins the election.

The codebase achieves this by deploying a custom-defined structural architecture (`struct`) to securely couple candidate identifications with their respective vote counters. The logic is divided into two primary execution layers:
- **Linear Search Traversal ($O(n)$):** Utilizes conditional string comparison (`strcmp`) to match raw voter inputs against registered candidate keys, dynamically validating votes in real-time.
- **Max-Element Evaluation ($O(n)$):** Executes a two-pass determination layout to securely capture the highest voting frequency and output multiple names simultaneously in the event of an electoral tie.

---

## 🚀 Execution & Setup

To compile and execute the project locally:

```bash
# Compile the source code using clang
make plurality

# Run the election simulation with candidate profiles
./plurality Alice Bob Charlie
```

