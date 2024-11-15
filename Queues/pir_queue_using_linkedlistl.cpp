#include <iostream>
using namespace std;

struct Node {
    int data;
    int priority;
    Node* next;

    Node(int value, int priority) : data(value), priority(priority), next(nullptr) {}
};

class PriorityQueueLinkedList {
private:
    Node* head;

public:
    PriorityQueueLinkedList() : head(nullptr) {}

    // Enqueue operation with priority
    void enqueue(int value, int priority) {
        Node* newNode = new Node(value, priority);
        if (head == nullptr || head->priority < priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Dequeue operation to remove the highest priority element
    void dequeue() {
        if (isEmpty()) {
            cout << "Priority Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node* temp = head;
        cout << "Dequeued: " << head->data << endl;
        head = head->next;
        delete temp;
    }

    // Peek operation to get the highest priority element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Priority Queue is empty." << endl;
            return -1;
        }
        return head->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Priority Queue is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << "(" << temp->data << ", priority: " << temp->priority << ") ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to delete all nodes
    ~PriorityQueueLinkedList() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    PriorityQueueLinkedList pq;
    pq.enqueue(10, 1);
    pq.enqueue(20, 3);
    pq.enqueue(30, 2);
    pq.display();  // Output: (20, priority: 3) (30, priority: 2) (10, priority: 1)

    cout << "Peek: " << pq.peek() << endl;  // Output: Peek: 20
    pq.dequeue();  // Dequeues 20
    pq.display();  // Output: (30, priority: 2) (10, priority: 1)

    pq.dequeue();  // Dequeues 30
    pq.display();  // Output: (10, priority: 1)

    pq.dequeue();  // Dequeues 10
    pq.display();  // Output: Priority Queue is empty.

    return 0;
}
