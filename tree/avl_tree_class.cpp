#include <iostream>
using namespace std;

// Node structure
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};
class Node{
    private:
        int key;
        Node* left;
        Node* right;
        int height;
    public:
    Node(int key) {
        node->key = key;
        node->left = node->right = nullptr;
        node->height = 1;
    }
    int height(void) {
        return height;
    }
    int balance() {
        return (left and right)?(left->height - right->height):0;
    }
    void rightRotate(void) {
//	    Node* T2 = x->right;
	
	    Node* x = left;
	    left = right;
	    right = x;
	
	    y->height = max(height(y->left), height(y->right)) + 1;
	    x->height = max(height(x->left), height(x->right)) + 1;
	
	    return x;
	}
    // Left rotation
    void leftRotate(void) {
        Node* y = right;
        
        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }
};

// Right rotation

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