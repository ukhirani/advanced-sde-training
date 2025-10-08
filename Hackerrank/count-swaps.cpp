#include <iostream>
#include <vector>
#include <algorithm> // Required for std::merge in some alternative implementations, though not strictly needed here.

// Function to merge two sorted subarrays
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors to hold the two subarrays
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    // Copy data to temporary vectors
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Merge the temporary vectors back into the original array
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged array

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr, if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr, if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Function to perform Merge Sort recursively
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // Find the middle point to divide the array into two halves
        int mid = left + (right - left) / 2;

        // Recursively sort the first half
        mergeSort(arr, left, mid);
        // Recursively sort the second half
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    std::vector<int> data = {12, 11, 13, 5, 6, 7};
    int n = data.size();

    std::cout << "Original array: ";
    for (int x : data) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    mergeSort(data, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int x : data) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
