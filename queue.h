#include<iostream>
#include<cstdlib>
using namespace std;

template <typename t>
class queue{
	private:
		t *val;
		int front;
		int rear;
		int maxsize;
		int size;
	public:
		queue(int msize=10){
			front=rear=-1;
			maxsize=msize;
			size=0;
			val=new t[maxsize];
		}
		bool isEmpty(){
			return front==rear;
		}
		bool isFull(){
			return (rear+1)%maxsize==front;
		}
		bool enqueue(t data){
			if(front==-1&&rear==-1){
				rear=(rear+1)%maxsize;
				front=(front+1)%maxsize;
				val[rear]=data;
				size++;
				return true;
			}
			else{
				if(isFull())
					return false;
				rear=(rear+1)%maxsize;
				val[rear]=data;
				size++;
				return true;
			}
			return true;
		}
		bool dequeue(t &data){
			if(isEmpty())
				return false;
			data=val[front];
			front=(front+1)%maxsize;
			size--;
			return true;	
		}
		void display(){
			cout<<endl<<"Queue Contains :"<<endl;
			for(int i=front,j=0;j<size;j++,i++){//,j++){
				cout<<val[(i)%maxsize]<<" ";
			}
		}
};
