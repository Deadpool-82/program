#include<iostream>
using namespace std;
template <class TYPE> class STACK 
{
	TYPE *arr;
	int top,maxsize;
	public:
		STACK <TYPE>(int msize=10)
		{
			top=-1;
			maxsize=msize;
			arr=new TYPE[maxsize];
		}
		bool isEmpty()
		{
			return top==-1;
		}
		bool isFull()
		{
			return top==maxsize;
		}
		bool push(TYPE data)
		{
			if(isFull())	return false;
			top=top+1;
			arr[top]=data;
			return true; 
		}
		bool pop(TYPE &data)
		{
			if(isEmpty())	return false;
			data=arr[top];
			top=top-1;
			return true;
		}
};
