#include <iostream>
using namespace std;

// Node structure
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Function to get the height of the tree
int height(Node* n) {
    return n ? n->height : 0;
}

// Helper function to create a new node
Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    node->height = 1;
    return node;
}

// Function to calculate the balance factor of a node
int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Insert function
Node* insert(Node* node, int key) {
    if (!node) 
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Find the node with the smallest value in a subtree
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left)
        current = current->left;
    return current;
}

// Delete function
Node* deleteNode(Node* root, int key) {
    if (!root)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;

            if (!temp) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// In-order traversal
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

	cout<<"Hight: "<<root->height<<endl;
	cout<<"root: "<<root->key<<endl;
	cout<<"L: "<<root->left->key<<endl;
	cout<<"LL: "<<root->left->left->key<<endl;
	cout<<"LR: "<<root->left->right->key<<endl;
	cout<<"R: "<<root->right->key<<endl;
	cout<<"RR: "<<root->right->right->key<<endl;
	
    cout << "In-order traversal of the AVL tree is:\n";
    inOrder(root);
    cout << endl;

    root = deleteNode(root, 40);

    cout << "In-order traversal after deleting 40:\n";
    inOrder(root);
    cout << endl;

    return 0;
}



/*
The provided code is an implementation of an AVL tree in C++. An AVL tree is a 
self-balancing binary search tree where the difference between the heights 
of the left and right subtrees of any node is at most 1.
This ensures that the tree remains balanced, 
which improves search, insertion, and deletion operations to O(log n) time complexity.
Here's a brief explanation of the code:

1. The `Node` structure represents a node in the AVL tree.
It contains the key value, pointers to the left and right child nodes, and the height of the node.

2. The `height` function calculates the height of a given node.
If the node is null, it returns 0; otherwise, it returns the height of the node.

3. The `createNode` function creates a new node with the given key value and initializes its left and right child pointers 
to null and its height to 1.

4. The `getBalance` function calculates the balance factor of a given node.
 It returns the difference between the heights of the left and right subtrees of the node.

5. The `rightRotate` function performs a right rotation on a given node.
 It creates a new node `x` by taking the left child of the given node `y`, 
 and then updates the pointers and heights accordingly.

6. The `leftRotate` function performs a left rotation on a given node. 
It creates a new node `y` by taking the right child of the given node `x`, 
and then updates the pointers and heights accordingly.

7. The `insert` function inserts a new node with the given key value into the AVL tree. 
It follows the standard binary search tree insertion process and then performs 
any necessary rotations to maintain the AVL tree property.

8. The `minValueNode` function finds the node with the smallest value in a given subtree. 
It traverses the left subtree until it reaches the leftmost node.

9. The `deleteNode` function deletes a node with the given key value from the AVL tree.
 It follows the standard binary search tree deletion process and then performs 
 any necessary rotations to maintain the AVL tree property.

10. The `inOrder` function performs an in-order traversal of the AVL tree and prints the keys of the nodes.

11. The `main` function demonstrates the usage of the AVL tree by inserting some nodes, printing the tree structure,
performing a deletion, and then printing the updated tree structure.

Overall, the code provides a complete implementation of an AVL tree in C++.
It includes functions for insertion, deletion, and traversal, 
as well as a main function to demonstrate the usage of the AVL tree.
*/