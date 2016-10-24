#include<iostream>

using namespace std;

template <class TYPE> class list
{
private:
	TYPE val;
	list *next;
public:
	list(TYPE value,list *givenList=NULL)
	{
		this->val = value;
		this->next = givenList;
	}

	int nodes()
	{
		int i;
		list *temp=this;
		for(i=1;temp=temp->next;i++);
		return i;
	}
	
	list* push_back(TYPE val)
	{
		if (!this) return new list<TYPE>(val);
		list *temp = this;
		while (temp->next) temp = temp->next;
		temp->next = new list<TYPE>(val);
		return this;		
	}
	
	list* erase(TYPE val)
	{
		if (!this) return this;
		list *temp=this;
		if(temp->val==val)
			return temp->next;
		while(temp->next)
		{
			if(temp->next->val==val)
			{
				temp->next=temp->next->next;
			}
			temp=temp->next;
		}
		return this;
	}
	list * insertAtPos(TYPE val,int n)
	{
		if (!this) return new list<TYPE>(val);
		list *temp = this;
		if(n==1)	return new list <TYPE> (val,temp);
		for(int i=1;i<n;i++)
			temp = temp->next;
		if(temp)
			temp->next = new list<TYPE>(val,temp->next);
		return this;	
	}
	list * deleteByPos(int n)
	{
		if (!this) return this;
		list *temp=this;
		if(n==1)
			return temp->next;
		for(int i=1;i<n;i++)
			temp=temp->next;
		temp->next=temp->next->next;
		return this;
	}
	
	int search(TYPE val)
	{
		list* temp=this;
		for(int i=1;temp->next;i++)
			if(temp->val==val)
				return i;
		return 0;
	}
	friend ostream& operator << (ostream &os, list *l)//overloading << for list objects
	{
		while (l) {	cout << l->val << " ";	l = l->next;	}
		return os;
	}
	
};
