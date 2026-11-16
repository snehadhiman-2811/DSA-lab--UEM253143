#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
};
Node *top = NULL;
// Linked List Traversal
void linkedListTraversal(Node *ptr) {
    if (ptr == NULL) {
        cout << "Stack is empty." << endl;
        return;
    }
    while (ptr != NULL) {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}
// Check if stack is empty
int isEmpty(Node *top) {
    return (top == NULL);
}
// Check if stack is full
int isFull() {
    Node *p = new(nothrow) Node;
    if (p == NULL)
        return 1;
    delete p;
    return 0;
}
// Push operation
Node* push(Node *top, int x) {
    if (isFull()) {
        cout << "Stack Overflow!" << endl;
        return top;
    }
    Node *n = new Node;
    n->data = x;
    n->next = top;
    top = n;
    return top;
}
// Pop operation
int pop(Node *tp) {
    if (isEmpty(tp)) {
        cout << "Stack Underflow!" << endl;
        return -1;
    }
    Node *n = tp;
    int x = n->data;
    top = tp->next;
    delete n;
    return x;
}
// Peek operation
int peek(int pos) {
    Node *ptr = top;
    if (pos <= 0)
        return -1;
    for (int i = 0; i < pos - 1 && ptr != NULL; i++)
        ptr = ptr->next;
    if (ptr != NULL)
        return ptr->data;
    else
        return -1;
}
// Display top element
int stackTop() {
    if (isEmpty(top)) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return top->data;
}
// Display stack
void display() {
    linkedListTraversal(top);
}
// Main function
int main() {
    int choice, x, pos;
    do {
        cout << "\n------ STACK ADT MENU ------" << endl;
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Stack Top\n6. Check Empty\n7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                top = push(top, x);
                break;
            case 2:
                if (!isEmpty(top))
                    cout << "Popped element: " << pop(top) << endl;
                else
                    pop(top);
                break;
            case 3:
                cout << "Enter position: ";
                cin >> pos;
                x = peek(pos);
                if (pos > 0) {
                    Node *ptr = top;
                    for (int i = 1; i < pos && ptr != NULL; i++)
                        ptr = ptr->next;
                    if (ptr != NULL)
                        cout << "Element at position " << pos << " is: " << x << endl;
                    else
                        cout << "Invalid position!" << endl;
                } else {
                    cout << "Invalid position!" << endl;
                }
                break;
            case 4:
                display();
                break;
            case 5:
                if (!isEmpty(top))
                    cout << "Top element: " << stackTop() << endl;
                else
                    stackTop();
                break;
            case 6:
                cout << (isEmpty(top) ? "Stack is Empty." : "Stack is Not Empty.") << endl;
                break;
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);
    while (!isEmpty(top))
        pop(top);
    return 0;
}
