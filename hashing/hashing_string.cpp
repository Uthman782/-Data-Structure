#include <iostream>
#include <list>
#include <string>
using namespace std;

// Class to implement hashing using a hash table with separate chaining
class HashTable {
private:
    int capacity; // Size of the hash table
    list<string>* table; // Array of linked lists

    // Hash function to map keys to table indices
    int hashFunction(string key) {
        int hash = 0;
        for (char ch : key) {
            hash = (hash * 31 + ch) % capacity;
        }
        return hash;
    }

public:
    // Constructor
    HashTable(int size) {
        capacity = size;
        table = new list<string>[capacity];
    }

    // Destructor
    ~HashTable() {
        delete[] table;
    }

    // Insert a key into the hash table
    void insert(string key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Search for a key in the hash table
    bool search(string key) {
        int index = hashFunction(key);
        for (const string& element : table[index]) {
            if (element == key) {
                return true;
            }
        }
        return false;
    }

    // Delete a key from the hash table
    void remove(string key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < capacity; ++i) {
            cout << "Index " << i << ": ";
            for (const string& element : table[i]) {
                cout << element << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    // Create a hash table of size 10
    HashTable ht(10);

    // Insert keys into the hash table
    ht.insert("Alice");
    ht.insert("Bob");
    ht.insert("Charlie");
    ht.insert("David");

    // Display the hash table
    cout << "Hash Table: " << endl;
    ht.display();

    // Search for keys
    cout << "\nSearching for 'Alice': " << (ht.search("Alice") ? "Found" : "Not Found") << endl;
    cout << "Searching for 'Eve': " << (ht.search("Eve") ? "Found" : "Not Found") << endl;

    // Remove a key
    cout << "\nRemoving 'Bob'." << endl;
    ht.remove("Bob");

    // Display the hash table after removal
    cout << "\nHash Table after removal: " << endl;
    ht.display();

    return 0;
}
