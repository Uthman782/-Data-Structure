#include<iostream>
using namespace std;
class array{
	private:
		int total_size;
		int used_size;
		int* ptr;
	public:
		array(int ts, int us=0):total_size(ts),used_size(us){	
			this->used_size=0;
			this->ptr=new int[ts];
		}
		// inserting function.. .
		bool insert(int number,int index=0){
			if(index<=this->used_size and this->used_size<this->total_size){
				for(int i=used_size; i>=index;i--){
					ptr[i+1]=ptr[i];
				}
				ptr[index]=number;
				used_size++;
				return (true);
				}
			else{return false;}
		}
		// deleting function.. .
		bool delet(int index){
			if(index<=this->used_size){
				ptr[index]=0;
				for(int i=index; i<used_size;i++){
					ptr[i]=ptr[i+1];
				}
				used_size--;
				return (true);
				}
			else{return false;}
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
inline int input(string ms, int val=0){
	cout<<ms;
	if(!val)
		cin>>val;
	return val;
}
int main(void){
	array obj(5);
	char cond='y';
	while(cond=='y'){
		string ifInsert;
		ifInsert=obj.insert(input("Enter value: "),input("Enter index: "))?"Your value successfuly inserted.":"Your value not inserted.";
		obj.show();
		cout<<ifInsert<<endl;
		cout<<"Do you want to insert value [y/n]: ";
		cin>>cond;
	}
//	now deleting some value from the arr.. .
	obj.delet(input("Delete value at index: "));
	obj.show();
	return(0);
}