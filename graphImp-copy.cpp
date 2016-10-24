#include<iostream>
#include "LinkedList.cpp"
using namespace std;
template <class TYPE1,class TYPE2> class PAIR
{
	public:
		TYPE1 first;
		TYPE2 second;
		PAIR(TYPE1 first,TYPE2 second=1)
		{
			this->first=first;
			this->second=second;
		}
		bool operator==(PAIR p)
		{
			return this->first==p.first;
		}
};
class GraphList
{
	int size;
	list< PAIR<int,int>* > **arr;
	public:
		GraphList(int size)
		{
			this->size=size;
			arr=new list< PAIR<int,int> >*[size];
		}
		void addEdge(int x,int y,int weight=1)
		{
			arr[x]->push_back((new PAIR<int,int>(y,weight)));
			arr[y]->push_back((new PAIR<int,int>(x,weight)));
		}
		void deleteEdge(int x,int y)
		{
			arr[x]->erase((new PAIR<int,int>(y)));
			arr[y]->erase((new PAIR<int,int>(x)));
		}
		bool findEdge(int x,int y)
		{
			return (bool)arr[x]->search((new PAIR<int,int>(y)));
		}
		int findWeight(int x,int y)
		{
			return arr[x]->getVal(arr[x]->search((new PAIR<int,int>(y))));
		}
		/*friend void BFS(int x);
		friend void DFS(int x);*/
		/*void BFS(int start)
		{
			bool visited[size+1];
			memset(visited,false,sizeof(visited));
			deque<int> q;
			q.push_back(start);
			while(!q.empty())
			{
				start=q.front();
				q.pop_front();
				if(!visited[start])
				{
					cout<<start<<" ";
					list< pair<int,int> >::iterator it;
					for(it=arr[start].begin();it!=arr[start].end();it++)
						q.push_back((*it).first);
					visited[start]=true;
				}
			}
		}
		void DFS(int start)
		{
			bool visited[size+1];
			memset(visited,false,sizeof(visited));
			DFSimplement(start,visited);
		}
		void DFSimplement(int start,bool *visited)
		{
			cout<<start<<" ";
			visited[start]=true;
			list< pair<int,int> >::iterator it;
			for(it=arr[start].begin();it!=arr[start].end();it++)
				if(!visited[(*it).first])
					DFSimplement((*it).first,visited);
		}*/
};
/*class GraphMatrix
{
	int size;
	int **arr;
	public:
		GraphMatrix(int size)
		{
			this->size=size;
			arr=new int*[size];
			for(int i=0;i<size;i++)
				arr[i]=new int[size];
			for(int i=0;i<size;i++)
				for(int j=0;j<i;j++)
					arr[i][j]=arr[j][i]=-1;
		}
		void addEdge(int x,int y,int weight=1)
		{
			arr[x][y]=weight;
			arr[y][x]=weight;
		}
		void deleteEdge(int x,int y)
		{
			arr[x][y]=-1;
			arr[y][x]=-1;
		}
		bool findEdge(int x,int y)
		{
			if(arr[x][y]==-1)	return false;
			return true;			
		}
		int findWeight(int x,int y)
		{
			return arr[x][y];
		}
		/*friend void BFS(int x);
		friend void DFS(int x);*/
		/*void BFS(int start)
		{
			bool visited[size+1];
			memset(visited,false,sizeof(visited));
			deque<int> q;
			q.push_back(start);
			while(!q.empty())
			{
				start=q.front();
				q.pop_front();
				if(!visited[start])
				{
					cout<<start<<" ";
					for(int i=0;i<size;i++)
						if(arr[start][i]!=-1)
							q.push_back(i);
					visited[start]=true;
				}
			}
		}
		void DFS(int start)
		{
			bool visited[size+1];
			memset(visited,false,sizeof(visited));
			DFSimplement(start,visited);
		}
		void DFSimplement(int start,bool *visited)
		{
			cout<<start<<" ";
			visited[start]=true;
			for(int i=0;i<size;i++)
				if(arr[start][i]!=-1)
					if(!visited[i])
						DFSimplement(i,visited);
		}
		int minKeyPos(int *key,bool *set)
		{
			int min=INT_MAX,minpos;
			for(int i=0;i<size;i++)
			{
				if(!set[i]&&key[i]<min)
				{
					min=key[i];
					minpos=i;
				}
			}
			return minpos;
		}
		void primsMST()
		{
			bool MSTset[size+1];
			int key[size+1];
			int parent[size+1];
			for(int i=0;i<size+1;i++)	key[i]=INT_MAX;
			memset(MSTset,false,sizeof(MSTset));
			key[0]=0;
			parent[0]=-1;
			for(int i=0;i<size;i++)
			{
				int u=minKeyPos(key,MSTset);
				MSTset[u]=true;
				for(int j=0;j<size;j++)
				{
					if((arr[u][j]!=-1)&&(!MSTset[j])&&(arr[u][j]<key[j]))
					{
						key[j]=arr[u][j];
						parent[j]=u;
					}
				}
			}
			cout<<"EDGE\t\tWEIGHT\n";
			for(int i=1;i<size;i++)
			{
				cout<<i<<" - "<<parent[i]<<"\t\t"<<key[i]<<endl;
			}
		}
		void shortestPath(int x)
		{
			bool SPset[size+1];
			int key[size+1];
			//int parent[size+1];
			for(int i=0;i<size+1;i++)	key[i]=INT_MAX;
			memset(SPset,false,sizeof(SPset));
			key[x]=0;
			//parent[x]=-1;
			for(int i=0;i<size;i++)
			{
				int u=minKeyPos(key,SPset);
				SPset[u]=true;
				for(int j=0;j<size;j++)
				{
					if((arr[u][j]!=-1)&&(!SPset[j])&&(arr[u][j]+key[u]<key[j]))
					{
						key[j]=arr[u][j]+key[u];
						//parent[j]=u;
					}
				}
			}
			cout<<"Vertex\t\tDistance\n";
			for(int i=0;i<size;i++)
			{
				cout<<i<<"\t\t"<<key[i]<<endl;
			}
		}
};*/
int main()
{
	GraphList g(5);
	g.addEdge(0,1,2);
	g.addEdge(0,3,6);	
	g.addEdge(1,3,8);
	g.addEdge(1,4,5);
	g.addEdge(2,1,3);
	g.addEdge(2,4,7);
	g.addEdge(3,4,9);
	cout<<g.findEdge(0,1)<<" "<<g.findWeight(0,1)<<endl;
}
