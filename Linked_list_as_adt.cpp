#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = NULL;
// 1. Display linked list
void display() {
    if (head == NULL) {
        cout << "List is Empty!\n";
        return;
    }
    Node* ptr = head;
    cout << "Linked List: ";
    while (ptr != NULL) {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}
// 2. Insert at beginning
void insertAtFirst(int data) {
    Node* ptr = new Node;
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    cout << "Element inserted successfully.\n";
}
// 3. Insert at index (0-based)
void insertAtIndex(int data, int index) {
    if (index < 0) {
        cout << "Invalid Index!\n";
        return;
    }
    if (index == 0) {
        insertAtFirst(data);
        return;
    }
    Node* p = head;
    for (int i = 0; i < index - 1 && p != NULL; i++) {
        p = p->next;
    }
    if (p == NULL) {
        cout << "Invalid Index!\n";
        return;
    }
    Node* ptr = new Node;
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    cout << "Element inserted successfully.\n";
}
// 4. Insert at end
void insertAtEnd(int data) {
    Node* ptr = new Node;
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL) {
        head = ptr;
        return;
    }
    Node* p = head;

    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    cout << "Element inserted successfully.\n";
}
// 5. Insert after a given value
void insertAfterValue(int value, int data) {
    Node* p = head;
    while (p != NULL && p->data != value) {
        p = p->next;
    }
    if (p == NULL) {
        cout << "Value not found!\n";
        return;
    }
    Node* ptr = new Node;
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    cout << "Element inserted successfully.\n";
}
// 6. Delete first element
void deleteFirst() {
    if (head == NULL) {
        cout << "List is Empty!\n";
        return;
    }
    Node* ptr = head;
    head = head->next;
    delete ptr;
    cout << "First element deleted.\n";
}
// 7. Delete at index (0-based)
void deleteAtIndex(int index) {
    if (head == NULL || index < 0) {
        cout << "Invalid Index!\n";
        return;
    }
    if (index == 0) {
        deleteFirst();
        return;
    }
    Node* p = head;
    for (int i = 0; i < index - 1 && p != NULL; i++) {
        p = p->next;
    }
    if (p == NULL || p->next == NULL) {
        cout << "Invalid Index!\n";
        return;
    }
    Node* q = p->next;
    p->next = q->next;
    delete q;
    cout << "Element deleted successfully.\n";
}
// 8. Delete last element
void deleteAtLast() {
    if (head == NULL) {
        cout << "List is Empty!\n";
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        cout << "Last element deleted.\n";
        return;
    }
    Node* p = head;
    Node* q = head->next;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    delete q;
    cout << "Last element deleted.\n";
}
// 9. Delete by value
void deleteByValue(int value) {
    if (head == NULL) {
        cout << "List is Empty!\n";
        return;
    }
    if (head->data == value) {
        deleteFirst();
        return;
    }
    Node* p = head;
    Node* q = head->next;
    while (q != NULL && q->data != value) {
        p = p->next;
        q = q->next;
    }
    if (q == NULL) {
        cout << "Element not found!\n";
        return;
    }
    p->next = q->next;
    delete q;
    cout << "Element deleted successfully.\n";
}
// 10. Search an element
void search(int value) {
    Node* ptr = head;
    int index = 0;
    while (ptr != NULL) {
        if (ptr->data == value) {
            cout << "Element found at index " << index << endl;
            return;
        }
        ptr = ptr->next;
        index++;
    }
    cout << "Element not found!\n";
}
// 11. Count nodes
void countNodes() {
    int count = 0;
    Node* ptr = head;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    cout << "Total nodes: " << count << endl;
}
// 12. Main function
int main() {
    int choice, data, index, value;
    do {
        cout << "\n===== LINKED LIST ADT =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at Index\n";
        cout << "3. Insert at End\n";
        cout << "4. Insert After Value\n";
        cout << "5. Delete First\n";
        cout << "6. Delete at Index\n";
        cout << "7. Delete Last\n";
        cout << "8. Delete by Value\n";
        cout << "9. Search\n";
        cout << "10. Display\n";
        cout << "11. Count Nodes\n";
        cout << "12. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                insertAtFirst(data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                cout << "Enter index: ";
                cin >> index;
                insertAtIndex(data, index);
                break;
            case 3:
                cout << "Enter data: ";
                cin >> data;
                insertAtEnd(data);
                break;
            case 4:
                cout << "Enter existing value: ";
                cin >> value;
                cout << "Enter new data: ";
                cin >> data;
                insertAfterValue(value, data);
                break;
            case 5:
                deleteFirst();
                break;
            case 6:
                cout << "Enter index: ";
                cin >> index;
                deleteAtIndex(index);
                break;
            case 7:
                deleteAtLast();
                break;
            case 8:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteByValue(value);
                break;
            case 9:
                cout << "Enter value to search: ";
                cin >> value;
                search(value);
                break;
            case 10:
                display();
                break;
            case 11:
                countNodes();
                break;
            case 12:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }
    } while (choice != 12);
    // Free remaining allocated memory
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
