#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table;
    vector<bool> occupied;
    int size;

    // Hash functions for double hashing
    int hash1(int key) {
        return key % size;
    }

    int hash2(int key) {
        return 1 + (key % (size - 1));
    }

public:
    HashTable(int s) : size(s) {
        table.resize(size, -1);
        occupied.resize(size, false);
    }

    // Linear Probing
    void insertLinear(int key) {
        int index = hash1(key);
        int originalIndex = index;
        while (occupied[index]) {
            index = (index + 1) % size;
            if (index == originalIndex) {
                cout << "Table is full\n";
                return;
            }
        }
        table[index] = key;
        occupied[index] = true;
    }

    // Quadratic Probing
    void insertQuadratic(int key) {
        int index = hash1(key);
        int i = 1;
        int originalIndex = index;
        while (occupied[index]) {
            index = (originalIndex + i * i) % size;
            i++;
            if (index == originalIndex) {
                cout << "Table is full\n";
                return;
            }
        }
        table[index] = key;
        occupied[index] = true;
    }

    // Double Hashing
    void insertDoubleHash(int key) {
        int index = hash1(key);
        int step = hash2(key);
        int originalIndex = index;
        while (occupied[index]) {
            index = (index + step) % size;
            if (index == originalIndex) {
                cout << "Table is full\n";
                return;
            }
        }
        table[index] = key;
        occupied[index] = true;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (occupied[i])
                cout << i << ": " << table[i] << endl;
            else
                cout << i << ": " << "Empty" << endl;
        }
    }
};

int main() {
    int size = 10;
    HashTable ht(size);

    cout << "Inserting using Linear Probing:\n";
    ht.insertLinear(10);
    ht.insertLinear(20);
    ht.insertLinear(30);
    ht.insertLinear(25);
    ht.display();

    cout << "\nInserting using Quadratic Probing:\n";
    HashTable ht2(size);
    ht2.insertQuadratic(10);
    ht2.insertQuadratic(20);
    ht2.insertQuadratic(30);
    ht2.insertQuadratic(25);
    ht2.display();

    cout << "\nInserting using Double Hashing:\n";
    HashTable ht3(size);
    ht3.insertDoubleHash(10);
    ht3.insertDoubleHash(20);
    ht3.insertDoubleHash(30);
    ht3.insertDoubleHash(25);
    ht3.display();

    return 0;
}