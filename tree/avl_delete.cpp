#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int value) {
        this->data = value;
        this->left = nullptr; // by default it'll be null
        this->right = nullptr; // by default it'll be null
        this->height=1; // for calculating height
    }
};

// Function to get the height of the tree... 
int height(Node* n) {
    return n ? n->height : 0;
}

// Function to calculate the balance factor of a node...
int getbalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Right rotation ... .
Node* rightRotate(Node* n) {
    Node* x = n->left; // x have left node of n
    Node* T2 = x->right; // Tree2 have left right of n

    x->right = n; // x right have node n
    n->left = T2;// n node have Tree2 node 
    // delete T2;
    n->height = max(height(n->left), height(n->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotation.. .. . 
Node* leftRotate(Node* n) {
    Node* y = n->right;
    Node* T2 = y->left;

    y->left = n;
    n->right = T2;
    n->height = max(height(n->left), height(n->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int data) {
    if (!node) // if the node have nullptr..
        return new Node(data); // then create new node with data..

    if (data < node->data) // if value is less then the value in the root..
        node->left = insert(node->left, data); // insert it in left
    else if (data > node->data) 
        node->right = insert(node->right, data);
    else // if data is = node->data
        return node; // don't insert...

    node->height = 1 + max(height(node->left), height(node->right));
	
    int balance = getbalance(node);
	// balancing factor {-1, 0, 1} then return..
    if(balance==-1 or balance==0 or balance==1)
    	return node;
    // Left Left
    if (balance > 1 and data < node->left->data)
        return rightRotate(node);

    // right -  right
    if (balance < -1 and data > node->right->data)
        return leftRotate(node);

    // left - right
    if (balance > 1 and data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // right - left
    if (balance < -1 and data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// In-order traversal
void in_order(Node* root) {
    if (root) {
        in_order(root->left);
        cout << root->data << " ";
        in_order(root->right);
    }
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

int main() {
    Node* root = nullptr;
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 9);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 21);
    root = insert(root, 15);
    root = insert(root, 18);
    root = insert(root, 28);
    root = insert(root, 20);
    root = insert(root, 30);

	cout<<"data: "<<root->data<<endl;
	cout<<"Left subtree: "<<endl;
	cout<<"L: "<<root->left->data<<endl;
	cout<<"LL: "<<root->left->left->data<<endl;
	cout<<"LLL: "<<root->left->left->left->data<<endl;
	cout<<"LR: "<<root->left->right->data<<endl;
	cout<<"LRL: "<<root->left->right->left->data<<endl;
	cout<<"LRR: "<<root->left->right->right->data<<endl;
	cout<<"Right subtree: "<<endl;
	cout<<"R: "<<root->right->data<<endl;
	cout<<"RL: "<<root->right->left->data<<endl;
	cout<<"RLR: "<<root->right->left->right->data<<endl;
	cout<<"RL: "<<root->right->left->data<<endl;
	cout<<"RLL: "<<root->right->left->left->data<<endl;
	cout<<"RLR: "<<root->right->left->right->data<<endl;
	cout<<"Hight: "<<root->height<<endl;

    cout << "In-order traversing of the AVL tree is:\n";
    in_order(root);
    return 0;
}