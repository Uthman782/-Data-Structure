#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Helper function to heapify-up (maintain the heap property after insertion)
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    // Helper function to heapify-down (maintain the heap property after deletion)
    void heapifyDown(int index) {
        int size = heap.size();
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < size && heap[leftChild] > heap[largest])
            largest = leftChild;
        if (rightChild < size && heap[rightChild] > heap[largest])
            largest = rightChild;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Function to insert a new element into the heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Function to delete the maximum element (root) from the heap
    void deleteMax() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Function to get the maximum element in the heap
    int getMax() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return heap[0];
    }

    // Function to display the heap elements
    void display() {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap heap;

    // Insert elements into the heap
    heap.insert(50);
    heap.insert(30);
    heap.insert(40);
    heap.insert(10);
    heap.insert(20);

    cout << "Heap elements: ";
    heap.display();

    cout << "Maximum element: " << heap.getMax() << endl;

    // Delete the maximum element
    heap.deleteMax();
    cout << "Heap after deleting max: ";
    heap.display();

    return 0;
}
