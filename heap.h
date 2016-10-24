#include<iostream>

using namespace std;

template <class TYPE> class priorityQueueMax
{
	TYPE *arr;
	int size,maxSize;
	public:
		priorityQueueMax(int msize=50)
		{
			this->arr=new TYPE[msize];
			this->size=0;
			this->maxSize=msize;
		}
		void heapify(int hole)
		{
			int child=2*hole+1;
			TYPE temp=arr[hole];
			while(child<size)
			{
				if(child+1<size&&arr[child]<arr[child+1])
					child++;
				if(temp<arr[child])
				{
					arr[hole]=arr[child];
					hole=child;
				}
				else	break;
				child=2*hole+1;
			}
			arr[hole]=temp;
		}
		bool insertElement(TYPE val)
		{
			if(size==maxSize)	return false;
			int currPos=size++;
			arr[currPos]=val;
			while(currPos>0&&arr[(currPos-1)/2]<arr[currPos])
			{
				TYPE temp=arr[(currPos-1)/2];
				arr[(currPos-1)/2]=arr[currPos];
				arr[currPos]=temp;
				currPos=(currPos-1)/2;
			}
			return true;
		}
		bool deleteElement()
		{
			if(size==0)	return false;
			TYPE temp=arr[0];
			arr[0]=arr[--size];
			heapify(0);
			return true;
		}
		void print()
		{
			for(int i=0;i<size;i++)
				cout<<arr[i]<<" ";
		}
		TYPE peekValue()
		{
			return arr[0];
		}
};
template <class TYPE> class priorityQueueMin
{
	TYPE *arr;
	int size,maxSize;
	public:
		priorityQueueMin(int msize=50)
		{
			this->arr=new TYPE[msize];
			this->size=0;
			this->maxSize=msize;
		}
		void heapify(int hole)
		{
			int child=2*hole+1;
			TYPE temp=arr[hole];
			while(child<size)
			{
				if(child+1<=size&&arr[child]>arr[child+1])
					child++;
				if(temp>arr[child])
				{
					arr[hole]=arr[child];
					hole=child;
				}
				else	break;
				child=2*hole+1;
			}
			arr[hole]=temp;
		}
		bool insertElement(TYPE val)
		{
			if(size==maxSize)	return false;
			int currPos=size++;
			arr[currPos]=val;
			while(currPos>0&&arr[(currPos-1)/2]>arr[currPos])
			{
				TYPE temp=arr[(currPos-1)/2];
				arr[(currPos-1)/2]=arr[currPos];
				arr[currPos]=temp;
				currPos=(currPos-1)/2;
			}
			return true;
		}
		bool deleteElement()
		{
			if(size==0)	return false;
			TYPE temp=arr[0];
			arr[0]=arr[--size];
			heapify(0);
			return true;
		}
		void print()
		{
			for(int i=0;i<size;i++)
				cout<<arr[i]<<endl;
		}
		TYPE peekValue()
		{
			return arr[0];
		}
};

