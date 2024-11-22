#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}
// this function will return address of left in in_order node.
Node* Min(Node* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}
// Delete function form Binary search tree.
Node* delet(Node* root, int value) {
    if (root == nullptr) { // if root or node is null.
        return root; // it'll return the node.
    }
    if (value < root->data) {
        root->left = delet(root->left, value);
    } else if (value > root->data) {
        root->right = delet(root->right, value);
    } else {
        // Node having one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node having two children
        Node* temp = Min(root->right); // Min() is a func already def.
        root->data = temp->data;
        root->right = delet(root->right, temp->data);
    }
    return root;
}

// In-order (Left -> Root -> Right)
void in_order(Node* root) {
    if (root == nullptr) return;

    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "In-order Traversal: ";
    in_order(root);
    cout << endl;

    // Delete a node from BST.....
    cout << "Deleting 50..." << endl;
    root = delet(root, 50);

    cout << "In-order Traversal after deletion: ";
    in_order(root);
    cout << endl;

    return 0;
}
