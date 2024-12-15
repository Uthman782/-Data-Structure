#include <iostream>
#include <list>
//#include <string>
using namespace std;

// separate chaining
class HashTable {
	private:
		int capacity; // Size of hash table
		list<int>* table; // this is Array of linked lists

		// Hash function to map keys to table indices
		int hashFunction(int key) {
			int hash = 0;
//        for (char ch : key) {
			hash = (key) % capacity;
//        }
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
	char again='y';
	while(again=='y') {
		HashTable ht(10);
		for(int i=0; i<10; i++) {
			int val;
			cout<<"Enter value for hash "<<i<<": ";
			cin>>val;
			ht.insert(val);
		}
		cout << "Your Hash Table: " << endl;
		ht.display();
		int sea;
		while(again=='y') {
			cout<<"Search a value in hash: ";
			cin>>sea;
			cout << "Searching for "<<sea<<": ";
			cout<<(ht.search(sea) ? "Found" : "Not Found") << endl;
			cout<<"Search again [y/n]: ";
			cin>>again;
		}
		again = 'y';
		while(again=='y') {
			cout<<"Remove Value: ";
			cin>>sea;
			cout << "\nRemoving "<<sea<<": " << endl;
			ht.remove(sea);
			cout << "\nHash Table after remove: " << endl;
			ht.display();
			cout<<"Remove again [y/n]: ";
			cin>>again;
		}
		cout<<"Do you wnat it again [y/n]: ";
		cin>>again;
		system("CLS");
	}
	return 0;
}
