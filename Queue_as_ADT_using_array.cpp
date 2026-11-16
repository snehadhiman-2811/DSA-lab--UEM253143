#include <iostream>
using namespace std;
#define MAX 100
int queue[MAX];
int front = -1;
int rear = -1;
// 1. Enqueue - Insert element
void enqueue(int value) {
    if (rear == MAX - 1) {
        cout << "Queue Overflow!\n";
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    cout << "Element inserted successfully.\n";
}
// 2. Dequeue - Delete element
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow!\n";
        return;
    }
    cout << "Deleted element: " << queue[front] << endl;
    if (front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }
}
// 3. Peek - Show front element
void peek() {
    if (front == -1) {
        cout << "Queue is Empty!\n";
        return;
    }
    cout << "Front element: " << queue[front] << endl;
}
// 4. Display queue
void display() {
    if (front == -1) {
        cout << "Queue is Empty!\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}
// 5. Check if queue is empty
bool isEmpty() {
    return front == -1;
}
// 6. Check if queue is full
bool isFull() {
    return rear == MAX - 1;
}
int main() {
    int choice, value;
    do {
        cout << "\n===== QUEUE ADT USING ARRAY =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check Empty\n";
        cout << "6. Check Full\n";
        cout << "7. Exit\n";
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
                if (isFull())
                    cout << "Queue is Full.\n";
                else
                    cout << "Queue is Not Full.\n";
                break;
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid Choice!\n";
        }
    } while (choice != 7);
    return 0;
}
