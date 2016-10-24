#include "heap.h"

#include<iostream>

using namespace std;

enum CATEGORY {CIVIL,COMPUTER,ELECTRICAL,MECHANICAL,MEDICINE};
ostream& operator<<(ostream &os,CATEGORY c)
{
	switch(c)
	{
		case 0: os<<"CIVIL";break;
		case 1: os<<"COMPUTER";break;
		case 2: os<<"ELECTRICAL";break;
		case 3: os<<"MECHANICAL";break;
		case 4: os<<"MEDICINE";break;
	}
	return os;
}
static int temp=0;
class candidate
{
	int id,addWt;
	string name;
	CATEGORY category;
	public:
		candidate()
		{
			id=temp++;
			addWt=(rand()%3)*2;
			name="";
			category=CATEGORY(rand()%5);
		}
		void setId(int id)
		{
			this->id=id;
		}
		void setName(string name)
		{
			this->name=name;
		}
		CATEGORY getCategory()
		{
			return category;
		}
		bool operator> (candidate temp)
		{
			return (this->id-this->addWt>temp.id-temp.addWt);
		}
		bool operator< (candidate temp)
		{
			return (this->id-this->addWt<temp.id-temp.addWt);
		}
		friend ostream& operator<< (ostream &os,candidate t)
		{
			os<<t.id<<"\t"<<t.name<<"\t"<<t.category<<"\t"<<t.addWt<<endl;
			return os;
		}
};
class employmentExchange
{
	priorityQueueMin <candidate> civil,comp,elec,mech,med;
	public:
		employmentExchange()
		{
			
		}
		void registration(candidate c)
		{
			string name;
			cout<<"Enter Name: ";
			cin>>name;
			c.setName(name);
			cout<<"Regitered:\t"<<c<<endl;
			switch(c.getCategory())
			{
				case 0: civil.insertElement(c);break;
				case 1: comp.insertElement(c);break;
				case 2: elec.insertElement(c);break;
				case 3: mech.insertElement(c);break;
				case 4: med.insertElement(c);break;
			}
		}
		void appoint(int noOfAvailabilities,CATEGORY category)
		{
			candidate c;
			bool flag;
			cout<<"Following Candidates have been appointed:"<<endl;
			for(int i=0;i<noOfAvailabilities;i++)
			{
				switch(category)
				{
					case 0: c=civil.peekValue();flag=civil.deleteElement();break;
					case 1: c=comp.peekValue();flag=comp.deleteElement();break;
					case 2: c=elec.peekValue();flag=elec.deleteElement();break;
					case 3: c=mech.peekValue();flag=mech.deleteElement();break;
					case 4: c=med.peekValue();flag=med.deleteElement();break;
				}
				if(flag)
					cout<<c;
				else
					break;
			}
			if(!flag)	cout<<"No more Candidates Available"<<endl;
		}
};
int main()
{
	employmentExchange ex;
	int n;
	cout<<"Enter the number of candidates: ";
	cin>>n;
	for(int i=0;i<n;i++)
		ex.registration(*(new candidate()));
	cout<<"1.CIVIL\n2.COMPUTER\n3.ELECTRICAL\n4.MECHANICAL\n5.MEDICINE\n";
	while(true)
	{
		int m,c;
		cout<<"Enter the category and the no of availabilities(enter 99 99 to exit): ";
		cin>>c>>m;
		if(c==99&&m==99)	break;
		ex.appoint(m,CATEGORY(c-1));
	}
	return 0;
}
