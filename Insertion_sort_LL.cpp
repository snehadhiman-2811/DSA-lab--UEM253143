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

// Insertion Sort on Linked List
Node* insertionSort(Node* head) {
    Node* sorted = NULL;
    Node* current = head;

    while (current != NULL) {
        Node* nextNode = current->next;

        // Insert at beginning of sorted list
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        }
        else {
            Node* temp = sorted;

            // Find correct position
            while (temp->next != NULL &&
                   temp->next->data < current->data) {
                temp = temp->next;
            }

            current->next = temp->next;
            temp->next = current;
        }

        current = nextNode;
    }

    return sorted;
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

    head = insertionSort(head);

    cout << "\nLinked List After Insertion Sort:\n";
    display(head);

    // Free memory
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
