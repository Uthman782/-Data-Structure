#include <iostream>
#include <list>
using namespace std;

// open chaining
class HashTable {
	private:
		int capacity; // Size of hash table
		list<int>* table; // this is Array of linked lists

		// Hash function to map keys to table indices
		int hashFunction(int key) {
			int hash = 0;
			hash = (key) % capacity;
			return hash;
		}

	public:
		// Constructor
		HashTable(int size) {
			this->capacity = size;
			this->table = new list<int>[this->capacity];
		}

		// Destructor
		~HashTable() {
			delete[] this->table;
		}
		void insert(int key) {
			int index = hashFunction(key);
			table[index].push_back(key);
		}

		bool search(int key) {
			int index = hashFunction(key);
			for (const int& element : table[index]) {
				if (element == key) {
					return true;
				}
			}
			return false;
		}

		void remove(int key) {
			int index = hashFunction(key);
			table[index].remove(key);
		}

		void display() {
			for (int i = 0; i < capacity; ++i) {
				cout << "Index " << i << ": ";
				for (const int& element : table[i]) {
					cout << element << " -> ";
				}
				cout << "NULL" << endl;
			}
		}
};

int main() {
	HashTable ht(10);
	ht.insert(15);
	ht.insert(50);
	ht.insert(11);
	ht.insert(22);
	ht.insert(34);
	ht.insert(43);
	ht.insert(56);
	ht.insert(77);
	ht.insert(79);
	ht.insert(88);
	cout << "Your Hash Table: " << endl;
	ht.display();
	cout << "Searching for 1: ";
	cout<<(ht.search(1) ? "Found" : "Not Found") << endl;

	cout << "\nRemoving 11: " << endl;
	ht.remove(11);
	cout << "\nHash Table after remove: " << endl;
	ht.display();
return 0;
}
