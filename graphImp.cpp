#include<iostream>
#include<list>
#include<stdlib.h>
#include<deque>
using namespace std;
class GraphList
{
	int size;
	list< pair<int,int> > *arr;
	public:
		GraphList(int size)
		{
			this->size=size;
			arr=new list< pair<int,int> >[size];
		}
		void addEdge(int x,int y,int weight=1)
		{
			arr[x].push_back(make_pair(y,weight));
			arr[y].push_back(make_pair(x,weight));
		}
		void deleteEdge(int x,int y)
		{
			list< pair<int,int> >::iterator it;
			for(it=arr[x].begin();it!=arr[x].end();it++)
				if((*it).first==y)
					break;
			arr[x].erase(it);
			for(it=arr[y].begin();it!=arr[y].end();it++)
				if((*it).first==x)
					break;
			arr[y].erase(it);
		}
		bool findEdge(int x,int y)
		{
			list< pair<int,int> >::iterator it;
			for(it=arr[x].begin();it!=arr[x].end();it++)
				if((*it).first==y)
					return true;
			return false;
		}
		int findWeight(int x,int y)
		{
			if(!findEdge(x,y))	return -1;
			list< pair<int,int> >::iterator it;
			for(it=arr[x].begin();it!=arr[x].end();it++)
				if((*it).first==y)
					return (*it).second;
		}
		/*friend void BFS(int x);
		friend void DFS(int x);*/
		void BFS(int start)
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
		}
		void primsMst();
		
};
class GraphMatrix
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
		void BFS(int start)
		{
			bool visited[size+1];
			memset(visited,false,sizeof(visited));
			deque<int> q;
			q.push_back(start);
			visited[start]=true;
			while(!q.empty())
			{
				start=q.front();
				cout<<start<<" ";
				q.pop_front();
				for(int i=0;i<size;i++)
					if(arr[start][i]!=-1&&!visited[i])
					{
						q.push_back(i);
						visited[i]=true;
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
};
int main()
{
	GraphMatrix g(5);
	g.addEdge(0,1,2);
	g.addEdge(0,3,6);	
	g.addEdge(1,3,8);
	g.addEdge(1,4,5);
	g.addEdge(2,1,3);
	g.addEdge(2,4,7);
	g.addEdge(3,4,9);
	g.BFS(0);
	cout<<endl;
	g.DFS(0);
	cout<<endl;
	g.primsMST();
	cout<<endl;
	g.shortestPath(2);
}
