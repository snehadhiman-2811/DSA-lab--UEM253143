#include <iostream>
using namespace std;
// Print array
void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
// Partition function
int partition(int A[], int low, int high) {
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do {
        while (i <= high && A[i] <= pivot) {
            i++;
        }
        while (A[j] > pivot) {
            j--;
        }
        if (i < j) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    // Swap pivot with A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
// Quick Sort
void quickSort(int A[], int low, int high) {
    int partitionIndex;
    if (low < high) {
        partitionIndex = partition(A, low, high);
        // Sort left subarray
        quickSort(A, low, partitionIndex - 1);
        // Sort right subarray
        quickSort(A, partitionIndex + 1, high);
    }
}
int main() {
    int A[] = {9, 4, 4, 8, 7, 5, 6};
    int n = 7;
    cout << "Array before sorting: ";
    printArray(A, n);
    quickSort(A, 0, n - 1);
    cout << "Array after sorting: ";
    printArray(A, n);
    return 0;
}
