#include <algorithm>
#include <iostream>
#include <vector>

namespace {
constexpr int INSERTION_SORT_THRESHOLD = 10;

void insertionSort(std::vector<int>& values, int low, int high) {
    for (int i = low + 1; i <= high; ++i) {
        const int key = values[i];
        int j = i - 1;
        while (j >= low && values[j] > key) {
            values[j + 1] = values[j];
            --j;
        }
        values[j + 1] = key;
    }
}

int medianOfThree(std::vector<int>& values, int low, int high) {
    const int mid = low + (high - low) / 2;

    if (values[mid] < values[low]) std::swap(values[mid], values[low]);
    if (values[high] < values[low]) std::swap(values[high], values[low]);
    if (values[high] < values[mid]) std::swap(values[high], values[mid]);

    std::swap(values[mid], values[high - 1]);
    return values[high - 1];
}

void quickSort(std::vector<int>& values, int low, int high) {
    if (low >= high) return;

    if (high - low + 1 <= INSERTION_SORT_THRESHOLD) {
        insertionSort(values, low, high);
        return;
    }

    const int pivot = medianOfThree(values, low, high);
    int left = low;
    int right = high - 1;

    while (true) {
        while (values[++left] < pivot) {}
        while (values[--right] > pivot) {}

        if (left >= right) break;
        std::swap(values[left], values[right]);
    }

    std::swap(values[left], values[high - 1]);
    quickSort(values, low, left - 1);
    quickSort(values, left + 1, high);
}
}  // namespace

int main() {
    std::vector<int> values;
    int n;

    std::cout << "Enter number of elements: ";
    if (!(std::cin >> n) || n < 0) {
        std::cerr << "Invalid array size.\n";
        return 1;
    }

    values.resize(static_cast<std::size_t>(n));
    std::cout << "Enter " << n << " integers: ";
    for (int& value : values) {
        if (!(std::cin >> value)) {
            std::cerr << "Invalid input. Expected integers only.\n";
            return 1;
        }
    }

    if (!values.empty()) {
        quickSort(values, 0, static_cast<int>(values.size()) - 1);
    }

    std::cout << "Sorted array: ";
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i > 0) std::cout << ' ';
        std::cout << values[i];
    }
    std::cout << '\n';

    return 0;
}
