#include<iostream>
using namespace std;
template <typename t>class stack{
	private:
		t *val;
		int top;
		int maxsize;
	public:
		stack(int msize=10){
			top=-1;
			maxsize=msize;
			val=new t[maxsize];
		}
		bool isFull(){
			return top==maxsize-1;
		}
		bool isEmpty(){
			return top==-1;
		}
		bool push(t data){
			if(isFull())
				return false;
			top+=1;
			val[top]=data;
			return true;	
		}
		bool pop(t &data){
			if(isEmpty())
				return false;
			data=val[top];
			top-=1;
			return true;	
		}
		void display(){
			cout<<endl<<"Stack contains:"<<endl;
			for(int i=top;i>=0;i--){
				cout<<val[i]<<" ";
			}
		}
};int main(){
	stack <int> s(5);
	int x;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);//stack is full
	s.display();
	s.pop(x);
	cout<<endl<<x<<" is popped";
	s.pop(x);
	cout<<endl<<x<<" is popped";
	s.pop(x);
	cout<<endl<<x<<" is popped";
	s.pop(x);
	cout<<endl<<x<<" is popped";
	s.display();
}
