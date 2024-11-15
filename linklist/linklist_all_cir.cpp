#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* tail;  // Tail pointer for circular list

public:
    CircularLinkedList() : tail(nullptr) {}

    // Insert at the beginning
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;  // Link to itself
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    // Insert at the end
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
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
        if (tail == nullptr) {
            cout << "List is empty. Adding at head." << endl;
            insertAtHead(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = tail->next;
        for (int i = 0; i < position - 1 && temp != tail; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail) {
            tail = newNode;
        }
    }

    // Delete a node by value
    void deleteByValue(int value) {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* curr = tail->next;
        Node* prev = tail;
        do {
            if (curr->data == value) {
                if (curr == tail) {
                    if (tail->next == tail) {  // Only one element
                        delete tail;
                        tail = nullptr;
                    } else {
                        prev->next = curr->next;
                        tail = prev;
                        delete curr;
                    }
                } else {
                    prev->next = curr->next;
                    delete curr;
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);
        cout << "Value not found." << endl;
    }

    // Delete a node at a specific position (0-based index)
    void deleteAtPosition(int position) {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        if (position < 0) {
            cout << "Position must be non-negative." << endl;
            return;
        }
        Node* curr = tail->next;
        Node* prev = tail;
        for (int i = 0; i < position; i++) {
            prev = curr;
            curr = curr->next;
            if (curr == tail->next) {
                cout << "Position out of bounds." << endl;
                return;
            }
        }
        if (curr == tail) {
            if (tail->next == tail) {  // Only one element
                delete tail;
                tail = nullptr;
            } else {
                prev->next = curr->next;
                tail = prev;
                delete curr;
            }
        } else {
            prev->next = curr->next;
            delete curr;
        }
    }

    // Search for a value in the list
    bool search(int value) {
        if (tail == nullptr) {
            return false;
        }
        Node* temp = tail->next;
        do {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        } while (temp != tail->next);
        return false;
    }

    // Display the list
    void display() {
        if (tail == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = tail->next;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << "(back to head)" << endl;
    }

    // Delete the entire list
    void clear() {
        if (tail == nullptr) return;
        Node* current = tail->next;
        while (current != tail) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        delete tail;
        tail = nullptr;
    }

    // Destructor to delete the entire list
    ~CircularLinkedList() {
        clear();
    }
};

int main() {
    CircularLinkedList list;

    list.insertAtHead(3);
    list.insertAtTail(5);
    list.insertAtPosition(4, 1); // Insert 4 at position 1
    list.display(); // Output: 3 -> 4 -> 5 -> (back to head)

    list.deleteByValue(4);
    list.display(); // Output: 3 -> 5 -> (back to head)

    list.insertAtTail(10);
    list.insertAtTail(15);
    list.display(); // Output: 3 -> 5 -> 10 -> 15 -> (back to head)

    cout << "Search for 10: " << (list.search(10) ? "Found" : "Not Found") << endl;

    list.deleteAtPosition(2);
    list.display(); // Output: 3 -> 5 -> 15 -> (back to head)

    list.clear();
    list.display(); // Output: List is empty.

    return 0;
}
