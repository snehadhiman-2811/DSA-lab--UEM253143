#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* front = NULL;
Node* rear = NULL;
// 1. Enqueue - Insert element
void enqueue(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    // If queue is empty
    if (front == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << "Element inserted successfully.\n";
}
// 2. Dequeue - Delete element
void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow! Queue is Empty.\n";
        return;
    }
    Node* temp = front;
    cout << "Deleted element: " << front->data << endl;
    front = front->next;
    // If queue becomes empty
    if (front == NULL) {
        rear = NULL;
    }
    delete temp;
}
// 3. Peek - Display front element
void peek() {
    if (front == NULL) {
        cout << "Queue is Empty!\n";
        return;
    }
    cout << "Front element: " << front->data << endl;
}
// 4. Display queue
void display() {
    if (front == NULL) {
        cout << "Queue is Empty!\n";
        return;
    }
    Node* temp = front;
    cout << "Queue elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// 5. Check if queue is empty
bool isEmpty() {
    return front == NULL;
}
// Main function
int main() {
    int choice, value;
    do {
        cout << "\n===== QUEUE ADT USING LINKED LIST =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check Empty\n";
        cout << "6. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                if (isEmpty())
                    cout << "Queue is Empty.\n";
                else
                    cout << "Queue is Not Empty.\n";
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }
    } while (choice != 6);
    // Free remaining memory
    while (front != NULL) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;
    return 0;
}
