#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    // this is constructor for our nodes.
    Node(char value) {
        data = value;
        left = nullptr; // by default it'll be null
        right = nullptr; // by default it'll be null
    }
};

// Function for in-order traversing 
// here: Left-root-Right
void in_order(Node* root) {
    if (root == nullptr) return; // if no data
    in_order(root->left); // Left; recursive call
    cout << root->data << ", "; // root
    in_order(root->right); // right; recursive call
}

// Function for pre-order traversing
// root_Left_Right
void pre_order(Node* root) {
    if (root == nullptr) return;
    cout << root->data << ", ";// root; actual data.
    pre_order(root->left);// Left
    pre_order(root->right);// Right
}

// Method for post-order traversing
// Left_Right_root
void post_order(Node* root) {
    if (root == nullptr) return;
    post_order(root->left);// Left
    post_order(root->right);// Right
    cout << root->data << ", ";// root
}

int main() {
//    Node* root = nullptr;
// Memory allocation for all tree nodes.
    Node* root1 = new Node('A');
    Node* root2 = new Node('B');
    Node* root3 = new Node('C');
    Node* root4 = new Node('D');
    Node* root5 = new Node('E');
    Node* root6 = new Node('F');
    Node* root7 = new Node('G');
    
//    connecting nodes with each other
    root1->left=root2;
    root1->right=root3;
    
    root2->left=root4;
    root2->right=root5;
    
    root3->left=root6;
    root3->right=root7;
    
    cout << "In-order Traversing: {";
    in_order(root1); // root1 are the top root of the tree..
    cout <<"}"<< endl;

    cout << "Pre-order Traversing: {";
    pre_order(root1);
    cout <<"}"<< endl;

    cout << "Post-order Traversing: {";
    post_order(root1);
    cout <<"}"<< endl;

    return 0;
}
