#include<iostream>
#include<cstdlib>
using namespace std;

template<class t>
class lqueue{
	private:
		class node{
			public:
				t data;
				node* next;
		};
		node* front;
		node* rear;
	public:
		lqueue(){
			front=NULL;
			rear=NULL;
		}
		void enqueue(t ele){
			
			node* temp=new node;
			
			temp->data=ele;
			
			temp->next=NULL;
			
			if(front==NULL){
				front=temp;
				rear=temp;
			}
			else{
				rear->next=temp;
				rear=temp;
			}
		}
		bool dequeue(){
			node* temp = new node;
			if(front==NULL)
				return false;
			else{
				temp=front;
				front=front->next;
				delete(temp);
				return true;
			}	
			return false;
		}
		void display(){
			node* newnode = new node;
			newnode=front;
			cout<<endl<<"Queue contains:"<<endl;
			while(newnode!=NULL){
				cout<<newnode->data<<" ";
				newnode=newnode->next;
			}	
		}
		
};
