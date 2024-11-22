#include <iostream>
#define SIZE 5 // Define the maximum size of the queue

using namespace std;

// Define the structure for a Circular Queue
struct CircularQueue {
    int items[SIZE];
    int front, rear;

    // Constructor to initialize the queue
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1));
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Enqueue an element into the queue
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }

        // First element insertion
        if (front == -1) {
            front = 0;
        }

        // Wrap-around increment for `rear`
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        cout << "Inserted: " << element << endl;
    }

    // Dequeue an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        int element = items[front];

        // If this is the last element
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            // Wrap-around increment for `front`
            front = (front + 1) % SIZE;
        }

        return element;
    }

    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

// Main function to demonstrate Circular Queue
int main() {
    CircularQueue cq;

    // Perform operations
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cq.display();

    cout << "Dequeued: " << cq.dequeue() << endl;
    cout << "Dequeued: " << cq.dequeue() << endl;

    cq.display();

    cq.enqueue(60);
    cq.enqueue(70);

    cq.display();

    return 0;
}
