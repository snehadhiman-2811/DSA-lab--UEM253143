#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX];
int size = 0;

// Insert an element
void insert(int element, int pos) {
    if (size == MAX) {
        cout << "List is Full!\n";
        return;
    }

    if (pos < 1 || pos > size + 1) {
        cout << "Invalid Position!\n";
        return;
    }

    for (int i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = element;
    size++;

    cout << "Element inserted successfully.\n";
}

// Delete an element
void deleteElement(int pos) {
    if (size == 0) {
        cout << "List is Empty!\n";
        return;
    }

    if (pos < 1 || pos > size) {
        cout << "Invalid Position!\n";
        return;
    }

    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;

    cout << "Element deleted successfully.\n";
}

// Search an element
void search(int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            cout << "Element found at position " << i + 1 << endl;
            return;
        }
    }

    cout << "Element not found.\n";
}

// Display list
void display() {
    if (size == 0) {
        cout << "List is Empty!\n";
        return;
    }

    cout << "List: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, element, pos;

    do {
        cout << "\n--- FIXED LIST ADT ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element: ";
                cin >> element;
                cout << "Enter position: ";
                cin >> pos;
                insert(element, pos);
                break;

            case 2:
                cout << "Enter position to delete: ";
                cin >> pos;
                deleteElement(pos);
                break;

            case 3:
                cout << "Enter element to search: ";
                cin >> element;
                search(element);
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
