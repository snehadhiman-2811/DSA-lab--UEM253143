#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
};
// Create a new node
Node* createNode(int val) {
    Node *n = new Node;
    n->data = val;
    n->left = n->right = NULL;
    return n;
}
// Insert operation
Node* insert(Node *root, int val) {
    if (root == NULL)
        return createNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    else
        cout << "Duplicate values not allowed!" << endl;
    return root;
}
// Search operation
Node* search(Node *root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
// Find minimum value
Node* findMin(Node *root) {
    if (root == NULL) return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}
// Find maximum value
Node* findMax(Node *root) {
    if (root == NULL) return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}
// Delete operation
Node* deleteNode(Node *root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
// Check if BST is empty
int isEmpty(Node *root) {
    return (root == NULL);
}
// Delete entire tree
void destroyTree(Node *root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}
int main() {
    Node *root = NULL;
    int choice, val;
    do {
        cout << "\n------ BST ADT MENU ------" << endl;
        cout << "1. Insert\n2. Delete\n3. Search\n4. Find Minimum\n5. Find Maximum\n6. Check Empty\n7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                root = insert(root, val);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                if (search(root, val) != NULL) {
                    root = deleteNode(root, val);
                    cout << "Node deleted successfully." << endl;
                } else {
                    cout << "Element not found!" << endl;
                }
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> val;
                if (search(root, val) != NULL)
                    cout << "Element found!" << endl;
                else
                    cout << "Element not found!" << endl;
                break;
            case 4:
                if (findMin(root) != NULL)
                    cout << "Minimum: " << findMin(root)->data << endl;
                else
                    cout << "Tree is empty!" << endl;
                break;
            case 5:
                if (findMax(root) != NULL)
                    cout << "Maximum: " << findMax(root)->data << endl;
                else
                    cout << "Tree is empty!" << endl;
                break;
            case 6:
                cout << (isEmpty(root) ? "Tree is Empty." : "Tree is Not Empty.") << endl;
                break;
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 10);
    destroyTree(root);
    return 0;
}
