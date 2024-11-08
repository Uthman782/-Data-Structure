#include <iostream>
using namespace std;

class Queue {
	private:
		int front, rear, ts;
		int* arr;
	public:
		Queue(int s): front(-1), rear(-1) {
			this->ts = s;
			this->arr = new int[this->ts]; /* queue */
		}
		int rer(){return rear;}
		int fron(){return front;}
		bool isFull(){
			if(this->front==0 and this->rear==this->ts-1)
				return(true);
			else if(this->rear==this->ts-1){
				return(true);
			}
			return false;
		}
		bool isEmpty(){
			if(this->front == -1 or this->front > this->rear)
				return true;
			return false;
		}

		void insert(int value) {
			if(this->isFull()) {
				cout << "Queue overflow... ." << endl;
				return;
			}
			this->front=(this->front == -1)?0:this->front;
			arr[++rear] = value;
			cout << value << " inserted into queue" << endl;
		}
		int delet() {
			if (this->isEmpty()) {
				cout << "Queue is empty!" << endl;
				return (-1);
			}
			int value = arr[front++];
			return value;
		}
		void display() {
			if (this->front == -1 or this->front > this->rear) {
				cout << "Queue is empty" << endl;
				return;
			}
			cout << "Queue elements: { ";
			for (int i = this->front; i <= this->rear; i++)
				cout << this->arr[i] << " ";
			cout<<"}"<<endl;
		}
		~Queue() {
			delete[] this->arr;
		}
};

int main() {
	Queue q(3);
//	q.display();
	q.insert(1);
	q.insert(1);
	q.insert(1);
//	q.display();
	q.delet();
	q.delet();
	q.delet();
	q.insert(1);
	q.insert(1);
	q.insert(1);
	q.insert(1);
	cout<<"Rear-> "<<q.rer()<<" and front-> "<<q.fron()<<endl;
	q.display();
	return 0;
}