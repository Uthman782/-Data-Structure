#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    // this is constructor for our node
    Node(int value) {
        data = value;
        left = nullptr; // by default it'll be null
        right = nullptr; // by default it'll be null
    }
};

// Function for inserting a node in the binary tree
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left=insert(root->left, value);
    } else {
        root->right=insert(root->right, value);
    }
    return root;
}

// Function for in-order traversal
void in_order(Node* root) {
    if (root == nullptr) return;

    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
}

// Function for pre-order traversal
void pre_order(Node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}

// Function for post-order traversal
void post_order(Node* root) {
    if (root == nullptr) return;

    post_order(root->left);
    post_order(root->right);
    cout << root->data << " ";
}

int main() {
//    Node* root = nullptr;
//    root = insert(root, 1);
//    cout<<root->data<<endl;
//    insert(root, 2);
//    cout<<root->right->data<<endl;
//    insert(root, 3);
//    cout<<root->right->right->data<<endl;
//    insert(root, 4);
//    cout<<root->right->right->right->data<<endl;
//    insert(root, 5);
//    cout<<root->right->right->right->right->data<<endl;
//    insert(root, 6);
//    cout<<root->right->right->right->right->right->data<<endl;
//    insert(root, 7);
//    cout<<root->right->right->right->right->right->right->data<<endl;

    Node* root = nullptr;
    root = insert(root, 5);
    insert(root, 6);
    insert(root, 4);
    insert(root, 7);
    insert(root, 3);
    insert(root, 8);
    insert(root, 2);
    insert(root, 9);
    insert(root, 1);
    insert(root, 10);
    cout << "In-order Traversal: ";
    in_order(root);
    cout << endl;

    cout << "Pre-order Traversal: ";
    pre_order(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    post_order(root);
    cout << endl;

    return 0;
}
