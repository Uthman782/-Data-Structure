#include<iostream>
using namespace std;

class array{
	private:
		int total_size;
		int used_size;
		int* ptr;
	public:
	array(int ts, int us=0):total_size(ts),used_size(us){
		this->ptr=new int[ts];
	}
	// inserting function.. .
	bool insert(int number,int index=0){
		if(index<=this->used_size and this->used_size<this->total_size){
			for(int i=used_size; i>=index;i--)
				ptr[i+1]=ptr[i];
			ptr[index]=number;
			used_size++;
			return (true);
			}
		else{return false;}
	}
	// Binary searching in the array...
	int search(int ele){
		int low(0), high(this->used_size - 1), mid;
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
		// data show function.. .
		void show(){
			cout<<"Value"<<(used_size>1?"s ":" ")<<"-> ";
			for(int i=0;i<this->used_size;i++)
				cout<<(!i?"{ ":", ")<<ptr[i]<<(i==used_size-1?" }":"");
			cout<<endl;
		}
		~array(){
			cout<<"Deleting your Array!"<<endl;
			delete ptr;
		}
};
int main(void){
	array obj(10);
	obj.insert(2,0);
	obj.insert(3,0);
	obj.insert(4,1);
	obj.insert(5,2);
	obj.insert(6,3);
	obj.show();
	int s;
	cout<<"Enter value for search: ";
	cin>>s;
	if(obj.search(s)){
		cout<<"Yes found!"<<endl;
	}else{
		cout<<"Not found!"<<endl;
	}
	return(0);
}
