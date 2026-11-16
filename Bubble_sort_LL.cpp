#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
// Display linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
// Insert at end
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
        return newNode;
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
// Bubble Sort on Linked List
void bubbleSort(Node* head) {
    if (head == NULL)
        return;
    int swapped;
    Node* ptr;
    Node* last = NULL;
    do {
        swapped = 0;
        ptr = head;
        while (ptr->next != last) {
            if (ptr->data > ptr->next->data) {
                // Swap data
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
}
int main() {
    Node* head = NULL;
    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        head = insertAtEnd(head, value);
    }
    cout << "\nLinked List Before Sorting:\n";
    display(head);
    bubbleSort(head);
    cout << "\nLinked List After Bubble Sort:\n";
    display(head);
    // Free memory
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}
