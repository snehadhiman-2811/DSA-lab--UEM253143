#include <iostream>
using namespace std;
// Find maximum element
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
// Counting sort according to digit position
void countSort(int arr[], int n, int exp) {
    int output[100];
    int count[10] = {0};
    // Count occurrences of digits
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    // Calculate cumulative count
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    // Build output array
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;

        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    // Copy output to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
// Radix Sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
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
    if (n <= 0 || n > 100) {
        cout << "Invalid array size!";
        return 0;
    }
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] < 0) {
            cout << "Please enter non-negative numbers only.";
            return 0;
        }
    }
    cout << "\nArray before sorting:\n";
    display(arr, n);
    radixSort(arr, n);
    cout << "\nArray after Radix Sort:\n";
    display(arr, n);
    return 0;
}