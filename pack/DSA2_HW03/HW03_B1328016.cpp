#include <algorithm>
#include <chrono>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using IntList = std::vector<int>;
using BenchmarkClock = std::chrono::steady_clock;

struct BenchmarkResult {
    std::string algorithm;
    int n;
    int run;
    double elapsed_ms;
};

IntList generateRandomList(int size, int minValue, int maxValue, std::mt19937 &rng) {
    std::uniform_int_distribution<int> dist(minValue, maxValue);
    IntList values(size);
    for (int i = 0; i < size; i++) {
        values[i] = dist(rng);
    }
    return values;
}

void insertionSort(IntList &arr) {
    for (int i = 1; i < static_cast<int>(arr.size()); i++) {
        int key = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}


void heapifyDown(IntList &arr, int heapSize, int rootIndex) {
    while (true) {
        int largest = rootIndex;
        int left = 2 * rootIndex;
        int right = 2 * rootIndex + 1;

        if (left <= heapSize && arr[left - 1] > arr[largest - 1]) {
            largest = left;
        }
        if (right <= heapSize && arr[right - 1] > arr[largest - 1]) {
            largest = right;
        }

        if (largest == rootIndex) {
            break;
        }

        std::swap(arr[rootIndex - 1], arr[largest - 1]);
        rootIndex = largest;
    }
}

void heapSort(IntList &arr) {
    const int n = static_cast<int>(arr.size());
    if (n <= 1) {
        return;
    }

    for (int i = n / 2; i > 0; i--) {
        heapifyDown(arr, n, i);
    }

    for (int i = n; i > 1; --i) {
        std::swap(arr[0], arr[i - 1]);
        heapifyDown(arr, i - 1, 1);
    }
}

int medianOfThreeIndex(const IntList &arr, int low, int high) {
    int mid = low + (high - low) / 2;
    int a = arr[low];
    int b = arr[mid];
    int c = arr[high];

    if ((a <= b && b <= c) || (c <= b && b <= a)) {
        return mid;
    }
    if ((b <= a && a <= c) || (c <= a && a <= b)) {
        return low;
    }
    return high;
}

int partition(IntList &arr, int low, int high) {
    int pivotIndex = medianOfThreeIndex(arr, low, high);
    int pivotValue = arr[pivotIndex];
    std::swap(arr[pivotIndex], arr[high]);

    int storeIndex = low;
    for (int i = low; i < high; ++i) {
        if (arr[i] < pivotValue) {
            std::swap(arr[i], arr[storeIndex]);
            ++storeIndex;
        }
    }

    std::swap(arr[storeIndex], arr[high]);
    return storeIndex;
}

void quickSortImpl(IntList &arr, int low, int high) {
    if (low >= high) {
        return;
    }

    int p = partition(arr, low, high);

    if (p > 0) {
        quickSortImpl(arr, low, p - 1);
    }
    quickSortImpl(arr, p + 1, high);
}

void quickSort(IntList &arr) {
    if (arr.size() <= 1) {
        return;
    }
    quickSortImpl(arr, 0, static_cast<int>(arr.size()) - 1);
}

bool isSortedAscending(const IntList &arr) {
    for (int i = 1; i < static_cast<int>(arr.size()); ++i) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

std::vector<int> buildRangeSizes(int start, int end, int step) {
    std::vector<int> sizes;
    for (int n = start; n <= end; n += step) {
        sizes.push_back(n);
    }
    return sizes;
}

int main() {
    std::vector<int> sizes = buildRangeSizes(10000, 500000, 10000);
    int repeats = 3;
    std::uint32_t seed = static_cast<std::uint32_t>(std::random_device{}());

    std::mt19937 dataRng(seed);

    std::cout << "algorithm,n,run,elapsed_ms" << '\n';

    for (int n : sizes) {
        for (int run = 1; run <= repeats; run++) {
            IntList base = generateRandomList(n, 1, 50000, dataRng);

            {
                IntList values = base;
                auto start = BenchmarkClock::now();
                heapSort(values);
                auto end = BenchmarkClock::now();
                if (!isSortedAscending(values)) {
                    std::cerr << "HeapSort failed to sort correctly for n=" << n << '\n';
                    return 2;
                }
                std::chrono::duration<double, std::milli> elapsed = end - start;
                std::cout << "HeapSort," << n << ',' << run << ',' << std::fixed << std::setprecision(6)
                          << elapsed.count() << '\n';
            }

            {
                IntList values = base;
                auto start = BenchmarkClock::now();
                insertionSort(values);
                auto end = BenchmarkClock::now();
                if (!isSortedAscending(values)) {
                    std::cerr << "InsertionSort failed to sort correctly for n=" << n << '\n';
                    return 2;
                }
                std::chrono::duration<double, std::milli> elapsed = end - start;
                std::cout << "InsertionSort," << n << ',' << run << ',' << std::fixed << std::setprecision(6)
                          << elapsed.count() << '\n';
            }

            {
                IntList values = base;
                auto start = BenchmarkClock::now();
                quickSort(values);
                auto end = BenchmarkClock::now();
                if (!isSortedAscending(values)) {
                    std::cerr << "QuickSort failed to sort correctly for n=" << n << '\n';
                    return 2;
                }
                std::chrono::duration<double, std::milli> elapsed = end - start;
                std::cout << "QuickSort," << n << ',' << run << ',' << std::fixed << std::setprecision(6)
                          << elapsed.count() << '\n';
            }
        }
    }

    return 0;
}
