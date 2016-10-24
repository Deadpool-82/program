#include<iostream>
using namespace std;
template <class TYPE> class LLIST
{
	private:
		TYPE val;
		LLIST *next;
	public:
		LLIST(TYPE value)
		{
			this->val = value;
			this->next = NULL;
		}
		LLIST(TYPE value, LLIST* givenList)
		{
			this->val = value;
			this->next = givenList;
		}
		LLIST * operator +(TYPE val)
		{
			if (!this) return new LLIST<TYPE>(val);
			LLIST *temp = this;
			if(temp->val>val)
				return new LLIST<TYPE>(val,temp);
			while (temp->val<val&&temp->next)
			{
				if(temp->next->val>val)
					break;
				temp = temp->next;
			}
			temp->next = new LLIST<TYPE>(val,temp->next);
			return this;		
		}
		LLIST * operator +(LLIST *l2)
		{
			LLIST *l3=NULL,*l1=this;
			while(l1)
			{
				l3=(*l3)+l1->val;
				l1=l1->next;
			}
			while(l2)
			{
				l3=(*l3)+l2->val;
				l2=l2->next;
			}
			return l3;
		}
		int operator +()
		{
			int sum=0;
			LLIST *temp=this;
			while(temp)
			{
				sum=sum+temp->val;
				temp=temp->next;
			}
			return sum;
		}
		friend ostream& operator << (ostream &os, LLIST *l)
		{
			while (l) {	cout << l->val << " ";	l = l->next;	}
			return os;
		}
};
int main()
{
	LLIST <int> *myList1 = NULL,*myList2=NULL,*mergedList=NULL;
	int a,b;
	cout<<"Enter number of elements in List 1 and List 2: ";
	cin>>a>>b;
	for(int i=0;i<a;i++)
		myList1 = (*myList1)+rand()%100;
	cout <<"LIST 1:"<< myList1<<endl;
	for(int i=0;i<b;i++)
		myList2 = (*myList2)+rand()%100;
	cout <<"LIST 2:"<<myList2<<endl;
	int sum1=+(*myList1);
	cout <<"Sum of elements in LIST 1 is: "<<sum1<<endl;
	int sum2=+(*myList2);
	cout <<"Sum of elements in LIST 2 is: "<<sum2<<endl;
	mergedList=(*myList1)+myList2;
	cout<<"Merged List is: "<<mergedList<<endl;
	return 0;
}
