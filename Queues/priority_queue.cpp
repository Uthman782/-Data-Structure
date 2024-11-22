#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the structure for an element in the priority queue
struct Node {
    int data;       // Value of the element
    int priority;   // Priority of the element

    // Constructor
    Node(int d, int p) : data(d), priority(p) {}
};

// Custom comparator for sorting based on priority
struct ComparePriority {
    bool operator()(Node const &a, Node const &b) {
        return a.priority > b.priority; // Min-heap: smallest priority first
    }
};

// Priority Queue class
class PriorityQueue {
private:
    vector<Node> heap; // Vector to represent the heap

    void heapifyUp(int index) {
        while (index > 0 && heap[(index - 1) / 2].priority > heap[index].priority) {
            swap(heap[(index - 1) / 2], heap[index]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left].priority < heap[smallest].priority)
            smallest = left;
        if (right < heap.size() && heap[right].priority < heap[smallest].priority)
            smallest = right;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Insert an element into the priority queue
    void push(int data, int priority) {
        Node newNode(data, priority);
        heap.push_back(newNode);
        heapifyUp(heap.size() - 1);
    }

    // Remove and return the element with the highest priority
    Node pop() {
        if (heap.empty()) {
            throw runtime_error("Priority queue is empty!");
        }
        Node top = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
        return top;
    }

    // Peek the element with the highest priority without removing it
    Node peek() const {
        if (heap.empty()) {
            throw runtime_error("Priority queue is empty!");
        }
        return heap.front();
    }

    // Check if the priority queue is empty
    bool empty() const {
        return heap.empty();
    }

    // Get the size of the priority queue
    size_t size() const {
        return heap.size();
    }
};

// Main function to demonstrate the Priority Queue
int main() {
    PriorityQueue pq;

    // Insert elements
    pq.push(10, 3);
    pq.push(20, 2);
    pq.push(30, 1);

    cout << "Elements popped in priority order:" << endl;
    while (!pq.empty()) {
        Node top = pq.pop();
        cout << "Data: " << top.data << ", Priority: " << top.priority << endl;
    }

    return 0;
}
