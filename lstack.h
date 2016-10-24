#include<iostream>
#include<cstdlib>
using namespace std;

template<typename t>
class lstack{
	private:
		class node{
		public:
			t data;
			node* next;
		};
		int top;
		int maxsize;
		node*  val;
	public:
		lstack(int msize=10){
			val=NULL;
			maxsize=msize;
			top=-1;
		}
		bool isFull(){
			return top==maxsize-1;
		}
		bool push(t ele){
			if(isFull())
				return false;
			node* newval = new node;
			if(val==NULL){
				newval->data=ele;
				newval->next=NULL;
				val= newval;
				top++;
			}
			else{
				newval->data=ele;
				newval->next=val;
				val=newval;
				top++;
			}
					
		}
		bool isEmpty(){
			return top==-1;
		}
		bool pop(){
			if(isEmpty())
				return false;
			else{
				node* prevval = val;
				val=val->next;
				top--;
				delete(prevval);
			}	
		}
		void print(){
			node* temp;
			temp=val;
			cout<<endl<<"Stack contains:"<<endl;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
};
