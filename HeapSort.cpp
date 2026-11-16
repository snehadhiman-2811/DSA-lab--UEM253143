#include <iostream>
using namespace std;
// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Heapify function
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // Check left child
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    // Check right child
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    // If largest is not root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        // Recursively heapify affected subtree
        heapify(arr, n, largest);
    }
}
// Heap Sort
void heapSort(int arr[], int n) {
    // Step 1: Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        // Move root (largest) to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        // Heapify reduced heap
        heapify(arr, i, 0);
    }
}
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array before sorting: ";
    printArray(arr, n);
    heapSort(arr, n);
    cout << "Array after sorting: ";
    printArray(arr, n);
    return 0;
}
