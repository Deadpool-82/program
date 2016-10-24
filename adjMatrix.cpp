#include<iostream>
#include<stdlib.h> 
#include<deque>
using namespace std;
class Graph
{
	int V ; 
	int **adjMatrix;
	public:
		Graph(int V)
		{
			this->V=V;
			adjMatrix = new int* [V];
			for(int i=0;i<V;i++)
				adjMatrix[i]= new int[V];
			//memset(adjMatrix , 0, sizeof(adjMatrix ));
		}
		
		void addEdge(int baseNode, int connectedNode , int weight )
		{
			adjMatrix[baseNode][connectedNode]=weight;
			adjMatrix[connectedNode][baseNode]=weight; //comment this line for directed graph
		}
		
		void deleteEdge(int baseNode , int connectedNode)
		{
			adjMatrix[baseNode][connectedNode]=0;
		}
		
		bool findEdge(int baseNode, int connectedNode)
		{
			if(adjMatrix[baseNode][connectedNode])
				return true;
			else
				return false;
		}
		
		int findWeight(int baseNode, int connectedNode)
		{
			return adjMatrix[baseNode][connectedNode];
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
				for(int i=0;i<V;i++)
				{
					if(adjMatrix[s][i]&&!visited[i])
					{
						visited[i]=true;
						q.push_back(i);
					}
				}
			}
		}
		
		void DFSactual(bool *visited, int baseNode)
		{
			visited[baseNode]=true;
			cout<<baseNode<<" ";
			for(int i=0;i<V;i++)
			{
				if(adjMatrix[baseNode][i]&&!visited[i])
				DFSactual(visited,i);
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
	cout<<endl<<"BFS from node 0 "<<endl;
	g.BFS(0);
	cout<<endl<<"DFS from node 0 "<<endl;
	g.DFS(0);
}
