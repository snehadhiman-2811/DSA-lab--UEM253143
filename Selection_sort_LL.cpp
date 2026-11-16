
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

// Insert node at end
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

// Selection Sort
void selectionSort(Node* head) {
    Node* i;
    Node* j;
    Node* minNode;

    for (i = head; i != NULL; i = i->next) {
        minNode = i;

        for (j = i->next; j != NULL; j = j->next) {
            if (j->data < minNode->data) {
                minNode = j;
            }
        }

        // Swap data
        if (minNode != i) {
            int temp = i->data;
            i->data = minNode->data;
            minNode->data = temp;
        }
    }
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

    selectionSort(head);

    cout << "\nLinked List After Selection Sort:\n";
    display(head);

    // Free memory
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
