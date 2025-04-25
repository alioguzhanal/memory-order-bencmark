# 🧵 Memory-Order Structures in Modern C++

This repository demonstrates how different `std::memory_order` options affect the performance of atomic operations in multi-threaded programs. Understanding memory ordering is essential for writing efficient and correct lock-free code.

## 📂 Contents

- `memory_order_benchmark.cpp`: Benchmarks different `std::memory_order` types under atomic operations.

---

# ⚡ Atomic Memory Order Benchmark

This example benchmarks different `std::memory_order` modes using a simple concurrent counter increment/decrement pattern.

## 📂 File

- `memory_order_benchmark.cpp`: Compares performance of atomic operations under different memory ordering constraints.

## 🧠 What You'll Learn

- How each memory order affects speed and behavior of atomic operations
- Why `memory_order_relaxed` is fastest but most dangerous
- When to use `acquire`, `release`, `acq_rel`, or `seq_cst`

## 🛠 Compilation

```bash
g++ -std=c++20 -O3 -pthread memory_order_benchmark.cpp -o mem_bench
./mem_bench
```

## 📊 Sample Output

> On Intel i7-1185G7 (Ubuntu 22.04, GCC 11)

```
Benchmarking atomic memory orders...
memory_order_relaxed: 620 ms
memory_order_acquire: 730 ms
memory_order_release: 715 ms
memory_order_acq_rel: 775 ms
memory_order_seq_cst: 1010 ms
```

## 📜 Explanation

| Memory Order         | Description                                                                 |
|----------------------|-----------------------------------------------------------------------------|
| `memory_order_relaxed` | Fastest. No synchronization or ordering guarantees. Use with caution.       |
| `memory_order_acquire`| Guarantees visibility of prior writes before read. Safe for readers.        |
| `memory_order_release`| Guarantees visibility of this write to other threads. Safe for writers.     |
| `memory_order_acq_rel`| Combines acquire + release for both read and write safety.                  |
| `memory_order_seq_cst`| Strongest and safest. Enforces a single global order. Slowest but correct.  |

---

This benchmark is part of the `lock-free-structures-cpp` repository. 🚀
