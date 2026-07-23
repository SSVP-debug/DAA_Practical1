#include <iostream>
using namespace std;

// Function to perform bubble sort
void bubbleSort(int arr[], int size) {
    for (int step = 0; step < size - 1; ++step) {
        bool swapped = false; // Early exit optimization tracker
        for (int i = 0; i < size - step - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Exit if array is sorted
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(data) / sizeof(data[0]);
    cout << "Original Array: ";
    printArray(data, size);
    bubbleSort(data, size);
    cout << "Sorted Array: ";
    printArray(data, size);
    return 0;
}
