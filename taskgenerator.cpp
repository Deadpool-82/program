#include "heap.h"
#include<vector>
static int temp=-150;
class taskGenerator
{
	enum UNIT {CPU,FPU,GPU};
	UNIT TYPE;
	int ID,PRIORITY;
	public:
		taskGenerator()
		{
			TYPE=UNIT(rand()%3);
			ID=temp++;
			PRIORITY=rand()%10;
		}
		UNIT getType()
		{
			return TYPE;
		}
		void setId(int i)
		{
			ID=i;
		}
		bool operator> (taskGenerator temp)
		{
			if(this->PRIORITY==temp.PRIORITY)
				return this->ID<temp.ID;
			return (this->PRIORITY>temp.PRIORITY);
		}
		bool operator< (taskGenerator temp)
		{
			if(this->PRIORITY==temp.PRIORITY)
				return this->ID>temp.ID;
			return (this->PRIORITY<temp.PRIORITY);
		}
		friend ostream& operator<< (ostream &os,taskGenerator t)
		{
			os<<t.TYPE<<"\t"<<t.ID<<"\t"<<t.PRIORITY<<endl;
			return os;
		}
};
class taskScheduler
{
	priorityQueueMax<taskGenerator> cpu,fpu,gpu;
	vector <taskGenerator> list;
	class triple
	{
		public:
			int cpu,fpu,gpu;
			triple()
			{
				cpu=rand()%2;
				fpu=rand()%2;
				gpu=rand()%2;
			}
			friend ostream& operator<< (ostream &os,triple t)
			{
				os<<"("<<t.cpu<<", "<<t.fpu<<", "<<t.gpu<<")"<<endl;
				return os;
			}
	};
	public:
		taskScheduler()
		{
			
		}
		void scheduleTasks()
		{
			triple temp;
			taskGenerator t;
			cout<<"Triple Generated: "<<temp;
			cout<<"Following Task were scheduled:"<<endl;
			cout<<"\tTYPE\tID\tPRIORITY"<<endl;
			if(temp.cpu==1)
			{
				cout<<"cpu:\t";
				t=cpu.peekValue();
				if(cpu.deleteElement())
				{
					cout<<t<<endl;
					list.push_back(t);
				}
				else	cout<<"No Tasks Available for cpu"<<endl;
			}
			if(temp.fpu==1)
			{
				cout<<"fpu:\t";
				t=fpu.peekValue();
				if(fpu.deleteElement())
				{
					cout<<t<<endl;
					list.push_back(t);
				}
				else	cout<<"No Tasks Available for fpu"<<endl;
			}
			if(temp.gpu==1)
			{
				cout<<"gpu:\t";
				t=gpu.peekValue();
				if(gpu.deleteElement())
				{
					cout<<t<<endl;
					list.push_back(t);
				}
				else	cout<<"No Tasks Available for gpu"<<endl;
			}
		}
		void generateTasks(int n)
		{
			cout<<"Following Task were generated:"<<endl;
			cout<<"TYPE\tID\tPRIORITY"<<endl;
			for(int i=0;i<n;i++)
			{
				taskGenerator t;
				cout<<t<<endl;
				switch(t.getType())
				{
					case 0:cpu.insertElement(t);break;
					case 1:fpu.insertElement(t);break;
					case 2:gpu.insertElement(t);break;
				}
			}
		}
		void print()
		{
			cout<<"TYPE\tID\tPRIORITY"<<endl;
			for(int i=0;i<list.size();i++)
			{
				cout<<list[i]<<endl;
			}
		}
};
int main()
{
	taskScheduler t;
	cout<<"Enter the number of tasks to generate: ";
	int n;
	cin>>n;
	t.generateTasks(n);
	char choice='y';
	while(true)
	{
		if(choice!='y')	break;
		t.scheduleTasks();
		cout<<"Enter y to continue: ";
		cin>>choice;
	}
	cout<<"Total Tasks Scheduled:"<<endl;
	t.print();
}
