#include <iostream>
using namespace std;
struct Stack {
    int size;
    int top;
    int *arr;
};
// Check whether stack is empty
int isEmpty(Stack *ptr) {
    if (ptr->top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}
// Check whether stack is full
int isFull(Stack *ptr) {
    if (ptr->top == ptr->size - 1) {
        return 1;
    }
    else return 0;
}
// Push operation
void push(Stack *ptr, int val) {
    if (isFull(ptr)) {
        cout << "Stack Overflow! Cannot push "
             << val << " to the stack." << endl;
    }
    else {
        ptr->top++;
        ptr->arr[ptr->top] = val;

        cout << val << " pushed into the stack." << endl;
    }
}
// Pop operation
int pop(Stack *ptr) {
    if (isEmpty(ptr)) {
        cout << "Stack Underflow! Cannot pop from the stack." << endl;
        return -1;
    }
    else {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
// Peek operation
// i = 1 means topmost element
int peek(Stack *sp, int i) {
    int arrayInd = sp->top - i + 1;
    if (i <= 0 || arrayInd < 0) {
        cout << "Not a valid position for the stack." << endl;
        return -1;
    }
    else {
        return sp->arr[arrayInd];
    }
}
// Display operation
void display(Stack *ptr) {
    if (isEmpty(ptr)) {
        cout << "Stack is empty." << endl;
    }
    else {
        cout << "Stack elements (Top to Bottom): " << endl;

        for (int i = ptr->top; i >= 0; i--) {
            cout << ptr->arr[i] << endl;
        }
    }
}
// Main function
int main() {
    Stack *sp = new Stack;
    sp->size = 10;
    sp->top = -1;
    sp->arr = new int[sp->size];
    cout << "Stack has been created successfully!" << endl;
    int choice, val, position;
    do {
        cout << "\n------ STACK ADT MENU ------" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                push(sp, val);
                break;
            case 2:
                val = pop(sp);
                if (val != -1 || !isEmpty(sp)) {
                    // This condition is not sufficient for -1 values;
                    // see the improved pop handling below if needed.
                }
                else {
                    break;
                }
                cout << "Popped element: " << val << endl;
                break;
            case 3:
                cout << "Enter position from top: ";
                cin >> position;
                val = peek(sp, position);
                if (position > 0 &&
                    sp->top - position + 1 >= 0) {
                    cout << "Element at position "
                         << position << " is: " << val << endl;
                }
                break;
            case 4:
                display(sp);
                break;
            case 5:
                if (isEmpty(sp)) {
                    cout << "Stack is Empty." << endl;
                }
                else {
                    cout << "Stack is Not Empty." << endl;
                }
                break;
            case 6:
                if (isFull(sp)) {
                    cout << "Stack is Full." << endl;
                }
                else {
                    cout << "Stack is Not Full." << endl;
                }
                break;
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);
    delete[] sp->arr;
    delete sp;
    return 0;
}
