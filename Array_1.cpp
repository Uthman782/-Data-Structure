#include<iostream>
using namespace std;
class arry{
	protected:
		int usize;
};
class array: public arry{
	private:
		int usize;
		int length;
		int arr[6];
	public:
		array(int us, int len):usize(us),length(length){}
		void insertion(int index, int value){
			this->arr[index]=value;
		}
		void updation(int index, int value){
			this->arr[index]=value;
		}										//  [0,1,2,3,4,5]->indexes
		void deletion(int ind_or_val, bool if_ind=true){// [1,2,3,4,5,6]->array
			if(if_ind){ // if index is given .. .   [1,2,4,5,6]->after deletion
				for(int i=ind_or_val; i<usize-1; i++)
					this->arr[i]=arr[i+1];
			}else{
				for(int i=0; i<this->usize; i++){
					if(this->arr[ind_or_val]==this->arr[i]){
						for(int j=i; j<i-1;j++)
							this->arr[j]=arr[j+1];
					}
				}
			}
		}
		void print(void){
			for(int i=0; i<6; i++)
				cout<<(i==0?"{ ":" ")<<this->arr[i]<<(i==5?" }":", ");
		}
};
int main(void){
//	int A={1,2,3,4,5,6};
	array obj(1,2);
	obj.insertion(0,10);
	obj.insertion(1,80);
	obj.insertion(2,50);
	obj.insertion(3,40);
	obj.insertion(4,30);
	obj.insertion(5,20);
//	obj.deletion(80, false);
	obj.updation(1,100);
	obj.print();
	return(0);
}