#include <iostream>
#include <vector>

// Function to merge two sorted sub-arrays into a single sorted sub-array
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors to hold the data
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    // Copy data to temporary vectors L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Merge the temporary vectors back into the original array
    int i = 0; // Initial index of the first sub-array
    int j = 0; // Initial index of the second sub-array
    int k = left; // Initial index of the merged sub-array

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Main function that implements Merge Sort recursively
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // Calculate the midpoint to prevent overflow errors
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Helper function to print the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    
    std::cout << "Original array: ";
    printArray(arr);

    // Perform Merge Sort on the entire array length
    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array:   ";
    printArray(arr);

    return 0;
}
