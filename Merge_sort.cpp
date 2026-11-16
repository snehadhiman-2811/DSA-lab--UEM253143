#include <iostream>
using namespace std;
// Merge two sorted subarrays
void merge(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;
    int temp[100];
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    // Copy remaining elements of left subarray
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    // Copy remaining elements of right subarray
    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    // Copy sorted elements back to original array
    for (int x = low; x <= high; x++) {
        arr[x] = temp[x];
    }
}
// Merge Sort
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        // Divide left half
        mergeSort(arr, low, mid);
        // Divide right half
        mergeSort(arr, mid + 1, high);
        // Merge both halves
        merge(arr, low, mid, high);
    }
}
// Display array
void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int arr[100], n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "\nArray before sorting:\n";
    display(arr, n);
    mergeSort(arr, 0, n - 1);
    cout << "\nArray after Merge Sort:\n";
    display(arr, n);
    return 0;
}
