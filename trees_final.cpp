#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// Node class for Binary Tree & BST
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// ********************** Binary Tree Functions **********************

// Recursive function to build a Binary Tree
Node* buildTree() {
    cout << "Enter the data (-1 for NULL): ";
    int data;
    cin >> data;

    if (data == -1) return nullptr;

    Node* root = new Node(data);
    cout << "Enter left child of " << data << endl;
    root->left = buildTree();
    cout << "Enter right child of " << data << endl;
    root->right = buildTree();
    
    return root;
}

// Level Order Traversal
void levelOrderTraversal(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == nullptr) {
            cout << endl;
            if (!q.empty()) q.push(nullptr);
        } else {
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}

// Inorder Traversal (Recursive)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal (Recursive)
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (Recursive)
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// ********************** Binary Search Tree (BST) Functions **********************

// Insert into BST
Node* insertIntoBST(Node*& root, int d) {
    if (root == nullptr) {
        root = new Node(d);
        return root;
    }

    if (d > root->data) root->right = insertIntoBST(root->right, d);
    else root->left = insertIntoBST(root->left, d);

    return root;
}

// Take input for BST
void takeInputBST(Node*& root) {
    int data;
    cout << "Enter elements for BST (-1 to stop): ";
    cin >> data;

    while (data != -1) {
        insertIntoBST(root, data);
        cin >> data;
    }
}

// Search in BST (Recursive)
bool searchInBST(Node* root, int x) {
    if (root == nullptr) return false;
    if (root->data == x) return true;

    if (root->data > x) return searchInBST(root->left, x);
    return searchInBST(root->right, x);
}

// Find Minimum Value Node
Node* minVal(Node* root) {
    while (root->left != nullptr) root = root->left;
    return root;
}

// Find Maximum Value Node
Node* maxVal(Node* root) {
    while (root->right != nullptr) root = root->right;
    return root;
}

// Delete a Node from BST
Node* deleteFromBST(Node* root, int val) {
    if (root == nullptr) return root;

    if (val < root->data) root->left = deleteFromBST(root->left, val);
    else if (val > root->data) root->right = deleteFromBST(root->right, val);
    else {
        // Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: One child
        if (root->left != nullptr && root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == nullptr && root->right != nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 3: Two children
        Node* temp = minVal(root->right);
        root->data = temp->data;
        root->right = deleteFromBST(root->right, temp->data);
    }
    return root;
}

// ********************** Main Function **********************
int main() {
    Node* root = nullptr;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Build Binary Tree\n";
        cout << "2. Insert into BST\n";
        cout << "3. Delete from BST\n";
        cout << "4. Search in BST\n";
        cout << "5. Level Order Traversal\n";
        cout << "6. Inorder Traversal\n";
        cout << "7. Preorder Traversal\n";
        cout << "8. Postorder Traversal\n";
        cout << "9. Find Min and Max in BST\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                root = buildTree();
                cout << "Binary Tree Created!\n";
                break;

            case 2:
                takeInputBST(root);
                cout << "BST Created!\n";
                break;

            case 3:
                int delVal;
                cout << "Enter value to delete from BST: ";
                cin >> delVal;
                root = deleteFromBST(root, delVal);
                cout << "Value deleted from BST.\n";
                break;

            case 4:
                int searchVal;
                cout << "Enter value to search in BST: ";
                cin >> searchVal;
                if (searchInBST(root, searchVal))
                    cout << "Element found in BST.\n";
                else
                    cout << "Element not found.\n";
                break;

            case 5:
                cout << "Level Order Traversal:\n";
                levelOrderTraversal(root);
                break;

            case 6:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 7:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 8:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 9:
                cout << "Min value in BST: " << minVal(root)->data << endl;
                cout << "Max value in BST: " << maxVal(root)->data << endl;
                break;

            case 10:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 10);

    return 0;
}
