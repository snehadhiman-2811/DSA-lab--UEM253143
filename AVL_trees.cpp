#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
    int data, height;
    Node *left, *right;
};
// Create a new node
Node* createNode(int val) {
    Node *n = new Node;
    n->data = val;
    n->height = 1;
    n->left = n->right = NULL;
    return n;
}
// Calculate height
int height(Node *root) {
    return (root == NULL) ? 0 : root->height;
}
// Calculate balance factor
int getBalance(Node *root) {
    return (root == NULL) ? 0 : height(root->left) - height(root->right);
}
// Right rotation (LL Case)
Node* rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}
// Left rotation (RR Case)
Node* leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
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
        return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int bf = getBalance(root);
    // LL Case
    if (bf > 1 && val < root->left->data)
        return rightRotate(root);
    // RR Case
    if (bf < -1 && val > root->right->data)
        return leftRotate(root);
    // LR Case
    if (bf > 1 && val > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // RL Case
    if (bf < -1 && val < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
// Find minimum node
Node* findMin(Node *root) {
    while (root->left != NULL)
        root = root->left;
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
        if (root->left == NULL || root->right == NULL) {
            Node *temp = root->left ? root->left : root->right;
            delete root;
            return temp;
        }
        else {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    if (root == NULL)
        return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int bf = getBalance(root);
    // LL Case
    if (bf > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    // LR Case
    if (bf > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // RR Case
    if (bf < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    // RL Case
    if (bf < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
// Search operation
Node* search(Node *root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}
// Inorder Traversal
void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
// Preorder Traversal
void preorder(Node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
// Postorder Traversal
void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
// Check if tree is empty
int isEmpty(Node *root) {
    return (root == NULL);
}
// Display tree height
void displayHeight(Node *root) {
    cout << "Height: " << height(root) << endl;
}
// Display balance factor of each node
void displayBalance(Node *root) {
    if (root != NULL) {
        cout << "Node " << root->data << ": "
             << getBalance(root) << endl;
        displayBalance(root->left);
        displayBalance(root->right);
    }
}
// Delete entire tree
void destroyTree(Node *root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}
// Main function
int main() {
    Node *root = NULL;
    int choice, val;
    do {
        cout << "\n------ AVL TREE ADT MENU ------" << endl;
        cout << "1. Insert\n2. Delete\n3. Search\n4. Inorder\n5. Preorder\n6. Postorder\n7. Height\n8. Balance Factor\n9. Check Empty\n10. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                if (search(root, val) != NULL)
                    cout << "Duplicate values not allowed!" << endl;
                else
                    root = insert(root, val);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                if (search(root, val) != NULL) {
                    root = deleteNode(root, val);
                    cout << "Node deleted successfully." << endl;
                } else
                    cout << "Element not found!" << endl;
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> val;
                cout << (search(root, val) ? "Element found!" : "Element not found!") << endl;
                break;
            case 4:
                cout << "Inorder: ";
                inorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Preorder: ";
                preorder(root);
                cout << endl;
                break;
            case 6:
                cout << "Postorder: ";
                postorder(root);
                cout << endl;
                break;
            case 7:
                displayHeight(root);
                break;
            case 8:
                if (isEmpty(root))
                    cout << "Tree is empty!" << endl;
                else
                    displayBalance(root);
                break;
            case 9:
                cout << (isEmpty(root) ? "Tree is Empty." : "Tree is Not Empty.") << endl;
                break;
            case 10:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 10);
    destroyTree(root);
    return 0;
}
