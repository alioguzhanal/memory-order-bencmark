#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <chrono>

constexpr size_t iterations = 100'000'000;

void benchmark(const std::string& label, std::memory_order order) {
    std::atomic<size_t> counter{0};

    auto start = std::chrono::high_resolution_clock::now();

    std::thread t1([&]() {
        for (size_t i = 0; i < iterations; ++i) {
            counter.fetch_add(1, order);
        }
    });

    std::thread t2([&]() {
        for (size_t i = 0; i < iterations; ++i) {
            counter.fetch_sub(1, order);
        }
    });

    t1.join();
    t2.join();

    auto end = std::chrono::high_resolution_clock::now();
    std::cout << label << ": "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms\n";
}

int main() {
    std::cout << "Benchmarking atomic memory orders...\n";
    benchmark("memory_order_relaxed", std::memory_order_relaxed);
    benchmark("memory_order_acquire", std::memory_order_acquire);
    benchmark("memory_order_release", std::memory_order_release);
    benchmark("memory_order_acq_rel", std::memory_order_acq_rel);
    benchmark("memory_order_seq_cst", std::memory_order_seq_cst);
    return 0;
}
