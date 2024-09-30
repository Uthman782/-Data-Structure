#include <iostream>
using namespace std;
class array{
private:
	int tsize; //tsize ==> total size,
	int usize; //usize ==> used size, of the array
	int temp;
	int *ptr;

public:
	array(int ts) : tsize(ts){
		this->usize = 0;
		this->ptr = new int[ts];
	}
	// linear searching in the array. .. .
	int linear(int ele){
		for (int i = 0; i < this->usize; i++)
			if (this->ptr[i] == ele)
				return i;
		return -1;
	}
	// sorting. .. .
 
// array sorting method ∙ bubble sort.
bool sort(bool asc = true) {
    if (asc) {
        for (int i = 0; i < this->usize - 1; i++) {
            for (int j = 0; j < this->usize - i - 1; j++) {
                if (this->ptr[j] > this->ptr[j + 1]) {
                    this->temp = this->ptr[j];
                    this->ptr[j] = this->ptr[j + 1];
                    this->ptr[j + 1] = this->temp;
                }
            }
        }
    } else {
        for (int i = 0; i < this->usize - 1; i++) {
            for (int j = 0; j < this->usize - i - 1; j++) {
                if (this->ptr[j] < this->ptr[j + 1]) {
                    this->temp = this->ptr[j];
                    this->ptr[j] = this->ptr[j + 1];
                    this->ptr[j + 1] = this->temp;
                }
            }
        }
    }
    return true;
}
	// binary searching in the array. .. .
	int binary(int ele){
		int low(0), high(this->usize - 1), mid;
		while (low <= high){
			mid = (low + high) / 2;
			if (this->ptr[mid] == ele)
				return mid;
			else if (this->ptr[mid] < ele)
				low = mid + 1;
			else
				high = mid - 1;
		}
		return -1;
	}
	// insertion method... .
	bool insert(int ele, int index = 0){
		if (index <= this->usize and this->usize < this->tsize){
			for (int i = usize; i >= index; i--)
				ptr[i + 1] = ptr[i];
			ptr[index] = ele;
			usize++;
			return (true);
		}
		else return (false);
	}
	// delete by index method.. .. .
	bool indexDelete(int index){
		if (index <= this->usize){
			this->temp = this->ptr[index];
			for (int i = index; i < this->usize; i++)
				ptr[i] = ptr[i + 1];
			usize--;
			return (true);
		}
		else return false;
	}
	
	// delete by value method.. .. .
	bool valueDelete(int value){
		int if_value_index=this->binary(value);
		if(if_value_index!=-1){
			this->temp = value;
			for (int i = if_value_index; i < this->usize; i++)
				this->ptr[i] = this->ptr[i + 1];
			this->usize--;
		}
		else return false;
	}
	// data show method.. .
	void show(){
		cout << "Value" << (usize > 1 ? "s " : " ") << "-> ";
		for (int i = 0; i < this->usize; i++)
			cout << (!i ? "{ " : ", ") << ptr[i] << (i == usize - 1 ? " }" : "");
		cout << endl;
	}
	~array(){
		cout << "Deleting your Array!" << endl;
		delete this->ptr;
	}
};
inline int input(string ms, int val = 0){
	cout << ms;
	if (!val)
		cin >> val;
	return val;
}
//           Main           //
int main(void){
	array arr(5);
	char cond = 'y';
	while (cond == 'y'){
		string ifInsert;
		ifInsert = arr.insert(input("Enter value: "), input("Enter index: ")) ? "Your value successfuly inserted." : "Your value not inserted.";
		arr.show();
		cout << ifInsert << endl;
		cout << "Do you want to insert value [y/n]: ";
		cin >> cond;
	}
	arr.sort(false);
	arr.show();
	//	now deleting some value from the arr.. .
	cond = 'y';
	while (cond == 'y'){
		string ifDelete;
		ifDelete = arr.valueDelete(input("Enter value: "))
					   ? "Your value successfuly deleted."
					   : "Your value isn't deleted.";
		arr.show();
		cout << ifDelete << endl;
		cout << "Do you want to delete value [y/n]: ";
		cin >> cond;
	}
	return (0);
}