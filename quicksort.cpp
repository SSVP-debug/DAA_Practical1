#include <iostream>
#include <vector>

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function places the pivot element at its correct position
// Elements smaller than pivot go to the left, larger to the right
int partition(std::vector<int>& arr, int low, int high) {
    // Choose the rightmost element as the pivot
    int pivot = arr[high]; 
    
    // Index of the smaller element, indicating the right position of pivot found so far
    int i = (low - 1); 

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    // Swap the pivot element with the greater element at i + 1
    swap(arr[i + 1], arr[high]);
    
    // Return the partition index
    return (i + 1);
}

// The main function that implements QuickSort
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is the partitioning index, arr[pi] is now at the right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the vector elements
void printArray(const std::vector<int>& arr) {
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = {10, 7, 8, 9, 1, 5};
    int n = data.size();

    std::cout << "Unsorted Array: ";
    printArray(data);

    // Call quickSort on the vector
    quickSort(data, 0, n - 1);

    std::cout << "Sorted Array: ";
    printArray(data);

    return 0;
}
