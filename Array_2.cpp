#include<iostream>
using namespace std;
class array{
	private:
		int total_size;
		int used_size;
		int* ptr;
	public:
		array(int ts, int us=0):total_size(ts),used_size(us){
			ptr = new int[ts];
			
		}
		bool insert(int number,int index,bool order=false){
			if(index<total_size){
				if(order==false){
					if(index<used_size){
						int temp;
						temp=ptr[index];
						ptr[index]=number;
						ptr[used_size]=temp;
						used_size++;
						return 1;
					}else{
						ptr[index]=number;
						used_size++;
						return 1;
					}
				}else{
					for(int i=used_size; i>=index;i--){
						int temp=ptr[i];
						ptr[i+1]=temp;
					}
					ptr[index]=number;
					used_size++;
				}
			}else{return 0;}
		}
		void show(){
			cout<<"Index"<<(used_size>1?"es":"")<<"-> ";
			for(int i=0;i<this->used_size;i++)
				cout<<(!i?"[ ":", ")<<i<<(i==used_size-1?" ]":"");
			cout<<endl<<"Value"<<(used_size>1?"s ":" ")<<"-> ";
			for(int i=0;i<this->used_size;i++)
				cout<<(!i?"{ ":", ")<<ptr[i]<<(i==used_size-1?" }":"");
		}
		~array(){
			delete ptr;
		}
};

int main(void){
	array obj(5);
	obj.insert(1,0);
	obj.insert(2,1);
	obj.insert(4,2);
	obj.insert(3,2, true);
	obj.show();
	return(0);
}