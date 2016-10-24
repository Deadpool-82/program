#include<iostream>
#include<vector>
#include<stdlib.h>
#include<deque>  //adjacency list, weighted, undirected graph 
#define pb push_back
#define mp make_pair
using namespace std;
class Graph 
{
	int V;
	vector< pair<int,int> > *a;
	public:
		Graph(int V)
		{
			this->V=V;
			a=new vector< pair<int,int>  > [V];
		}
		
		void addEdge(int baseNode, int connectedNode , int weight)
		{
			a[baseNode].pb( mp (connectedNode,weight ));
			a[connectedNode].pb( mp (baseNode,weight )); // comment this for directed graph
		}
		
		void removeEdge(int baseNode ,int connectedNode )
		{
			vector< pair<int,int> >::iterator i;
			for(i=a[baseNode].begin();i<a[baseNode].end();i++)
			{
				if((*i).first==connectedNode)
				{
					a[baseNode].erase(i);
					break;
				}
			}
			for(i=a[connectedNode].begin();i<a[connectedNode].end();i++)
			{
				if((*i).first==baseNode)
				{
					a[connectedNode].erase(i);
					break;
				}
			}
		}
		
		bool findEdge(int baseNode, int connectedNode)
		{
			vector< pair<int,int> >::iterator i;
			for(i=a[baseNode].begin();i<a[baseNode].end();i++)
			{
				if((*i).first==connectedNode)
				{
					return true;
				}
			}
			return false;
		}
		
		int findWeight( int baseNode , int connectedNode )
		{
			vector< pair<int,int> >::iterator i;
			for(i=a[baseNode].begin();i<a[baseNode].end();i++)
			{
				if((*i).first==connectedNode)
				{
					return (*i).second;
				}
			}
			return 0;
		}
		
		void BFS(int baseNode) //do a bfs from the selected baseNode
		{
			deque<int> q; //deque to add a node, remove it , and add all its connections 
			bool *visited = new bool[V+1];
			for(int i=0;i<=V;i++) visited[i]=false;
			q.push_back(baseNode);
			visited[baseNode]=true;
			while(!q.empty())
			{
				int s=q.front();
				cout<<s<<" ";
				q.pop_front();	
				vector< pair<int,int> >::iterator it;
				for(it=a[s].begin();it!=a[s].end();it++)
				{
					if(!visited[(*it).first])
					{
						visited[(*it).first]=true;
						q.push_back((*it).first);
					}
				}
			}
		}
		
		void DFSactual(bool *visited, int baseNode)
		{
			visited[baseNode]=true;
			cout<<baseNode<<" ";
			vector< pair<int,int > >::iterator it;
			for(it=a[baseNode].begin();it!=a[baseNode].end();it++)
			{
				if(!visited[(*it).first])
				DFSactual(visited,(*it).first);
			}
		}
	
		void DFS(int baseNode)
		{
			bool *visited=new bool[V];
			memset(visited,false,sizeof(visited));
			DFSactual(visited,baseNode);
		}
};

main()
{
	Graph g(5);
	g.addEdge(0,1,2);
	g.addEdge(0,3,6);
	g.addEdge(1,3,8);
	g.addEdge(1,4,5);
	g.addEdge(2,1,3);
	g.addEdge(2,4,7);
	g.addEdge(3,4,9);
	cout<<endl<<"BFS from node 1 "<<endl;
	g.BFS(0);
	cout<<endl<<"DFS from node 1 "<<endl;
	g.DFS(0);
	
}
