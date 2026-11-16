#include <iostream>
using namespace std;
struct Stack {
    int size;
    int top;
    char *arr;
};
// Check if stack is empty
int isEmpty(Stack *ptr) {
    return (ptr->top == -1);
}
// Check if stack is full
int isFull(Stack *ptr) {
    return (ptr->top == ptr->size - 1);
}
// Push operation
void push(Stack *ptr, char val) {
    if (isFull(ptr))
        cout << "Stack Overflow!" << endl;
    else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
// Pop operation
char pop(Stack *ptr) {
    if (isEmpty(ptr)) {
        cout << "Stack Underflow!" << endl;
        return '\0';
    }
    char val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}
// Parenthesis Matching
int parenthesisMatch(char *exp) {
    Stack *sp = new Stack;
    sp->size = 100;
    sp->top = -1;
    sp->arr = new char[sp->size];
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(sp, '(');
        }
        else if (exp[i] == ')') {
            if (isEmpty(sp)) {
                delete[] sp->arr;
                delete sp;
                return 0;
            }
            pop(sp);
        }
    }
    int result = isEmpty(sp);
    delete[] sp->arr;
    delete sp;

    return result;
}
int main() {
    char exp[] = "((8)(*--$$9))";
    if (parenthesisMatch(exp))
        cout << "The parenthesis is matching.";
    else
        cout << "The parenthesis is not matching.";
    return 0;
}
