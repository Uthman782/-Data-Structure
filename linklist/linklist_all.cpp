#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert at the beginning
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at a specific position (0-based index)
    void insertAtPosition(int value, int position) {
        if (position < 0) {
            cout << "Position must be non-negative." << endl;
            return;
        }
        if (position == 0) {
            insertAtHead(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position out of bounds." << endl;
            delete newNode;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Delete a node by value
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Value not found." << endl;
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }

    // Delete a node at a specific position (0-based index)
    void deleteAtPosition(int position) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (position < 0) {
            cout << "Position must be non-negative." << endl;
            return;
        }
        if (position == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds." << endl;
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }

    // Search for a value in the list
    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    // Delete the entire list
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Destructor to delete the entire list
    ~LinkedList() {
        clear();
    }
};

int main() {
    LinkedList list;

    list.insertAtHead(3);
    list.insertAtTail(5);
    list.insertAtPosition(4, 1); // Insert 4 at position 1
    list.display(); // Output: 3 -> 4 -> 5 -> nullptr

    list.deleteByValue(4);
    list.display(); // Output: 3 -> 5 -> nullptr

    list.insertAtTail(10);
    list.insertAtTail(15);
    list.display(); // Output: 3 -> 5 -> 10 -> 15 -> nullptr

    cout << "Search for 10: " << (list.search(10) ? "Found" : "Not Found") << endl;

    list.deleteAtPosition(2);
    list.display(); // Output: 3 -> 5 -> 15 -> nullptr

    list.clear();
    list.display(); // Output: List is empty.

    return 0;
}

/*
Certainly! I'll explain the `LinkedList` class and its methods:

**File: c:\Users\UTHMAN\Desktop\DS\linklist\linklist_all.cpp**

This class implements a singly linked list data structure. Here's a breakdown of its components:

1. Private member:
   - `Node* head`: Pointer to the first node of the list.

2. Constructor:
   - `LinkedList()`: Initializes an empty list with `head` set to `nullptr`.

3. Methods:
   a. `insertAtHead(int value)`:
      - Creates a new node with the given value.
      - Sets the new node's next pointer to the current head.
      - Updates the head to point to the new node.

   b. `insertAtTail(int value)`:
      - Creates a new node with the given value.
      - If the list is empty, sets the head to the new node.
      - Otherwise, traverses to the last node and links it to the new node.

   c. `insertAtPosition(int value, int position)`:
      - Inserts a new node with the given value at the specified position.
      - Handles edge cases like negative position or position out of bounds.

   d. `deleteByValue(int value)`:
      - Removes the first occurrence of a node with the given value.
      - Handles cases like empty list, deleting the head, and value not found.

   e. `deleteAtPosition(int position)`:
      - Removes the node at the specified position.
      - Handles edge cases similar to insertAtPosition.

   f. `search(int value)`:
      - Traverses the list to find a node with the given value.
      - Returns true if found, false otherwise.

   g. `display()`:
      - Prints the entire list, showing each node's data and the links between them.

   h. `clear()`:
      - Deletes all nodes in the list, freeing the allocated memory.

   i. Destructor `~LinkedList()`:
      - Calls clear() to ensure all memory is freed when the LinkedList object is destroyed.

This implementation provides a comprehensive set of operations for a singly linked list, including insertion at various positions, deletion by value and position, searching, displaying, and proper memory management. The class encapsulates the list operations, providing a clean interface for users to interact with the linked list data structure.
*/