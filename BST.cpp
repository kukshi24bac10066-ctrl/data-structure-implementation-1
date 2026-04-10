#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
};

// BST class
class BST {
public:
    // Insert node
    Node* insert(Node* root, int value) {
        if (root == NULL) {
            Node* newNode = new Node;
            newNode->data = value;
            newNode->left = newNode->right = NULL;
            return newNode;
        }

        if (value < root->data)
            root->left = insert(root->left, value);
        else
            root->right = insert(root->right, value);

        return root;
    }

    // Search node
    bool search(Node* root, int key) {
        if (root == NULL) return false;
        if (root->data == key) return true;

        if (key < root->data)
            return search(root->left, key);
        else
            return search(root->right, key);
    }

    // Inorder Traversal (Left, Root, Right)
    void inorder(Node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Preorder Traversal (Root, Left, Right)
    void preorder(Node* root) {
        if (root == NULL) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    // Postorder Traversal (Left, Right, Root)
    void postorder(Node* root) {
        if (root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};

// Main function
int main() {
    BST tree;
    Node* root = NULL;

    // Insert values
    root = tree.insert(root, 50);
    tree.insert(root, 30);
    tree.insert(root, 70);
    tree.insert(root, 20);
    tree.insert(root, 40);
    tree.insert(root, 60);
    tree.insert(root, 80);

    // Traversals
    cout << "Inorder Traversal: ";
    tree.inorder(root);

    cout << "\nPreorder Traversal: ";
    tree.preorder(root);

    cout << "\nPostorder Traversal: ";
    tree.postorder(root);

    // Search
    int key = 40;
    if (tree.search(root, key))
        cout << "\n" << key << " found in BST";
    else
        cout << "\n" << key << " not found in BST";

    return 0;
}