#include <iostream>
#include <vector>
using namespace std;

class Queue {
private:
    vector<int> data;
    int frontIndex; // Tracks the front of the queue

public:
    Queue() : frontIndex(0) {}

    // Enqueue operation
    void enqueue(int value) {
        data.push_back(value);
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else {
            frontIndex++;
        }
    }

    // Peek operation
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1; // Indicates an empty queue
        }
        return data[frontIndex];
    }

    // Check if queue is empty
    bool isEmpty() {
        return frontIndex >= data.size();
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        for (int i = frontIndex; i < data.size(); i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();  // Output: 10 20 30

    cout << "Peek: " << q.peek() << endl;  // Output: Peek: 10

    q.dequeue();
    q.display();  // Output: 20 30

    q.dequeue();
    q.display();  // Output: 30

    q.dequeue();
    q.display();  // Output: Queue is empty.

    return 0;
}
