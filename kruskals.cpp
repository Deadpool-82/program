

#include<bits/stdc++.h>
using namespace std;
struct subset
{
	int parent;
	int rank;
};
int find_parent(subset* subs, int i){
	if(subs[i].parent!=i)subs[i].parent = find_parent(subs,subs[i].parent);
	return subs[i].parent;
}
void Union(subset* subs, int u, int v){
	int x = find_parent(subs,u);
	int y = find_parent(subs,v);
	if(subs[x].rank==subs[y].rank){
		subs[y].parent = x;
		subs[x].rank++;
	}else if(subs[x].rank<subs[y].rank)subs[x].parent = y;
	else subs[y].parent = x;
}
bool comp(const pair<int, pair<int, int> > &a, const pair<int, pair<int, int> > &b){
	return a.first<b.first;
}
int main(void){
	int n,m,u,v,w;
	vector<pair<int, pair<int, int> > > edge;
	subset subs[100];
	cin>>n>>m;
	for(int i=0; i<m; i++){
		cin>>u>>v>>w;
		edge.push_back(make_pair(w,make_pair(u,v)));
	}
	sort(edge.begin(),edge.end(),comp);
	for(int i=0; i<n; i++){
		subs[i].parent=i;
		subs[i].rank=0;
	}
	vector<pair<int, pair<int, int> > > res;
	int i=0,j=0;
	while(i<n-1){
		int x = find_parent(subs, edge[j].second.first);
		int y = find_parent(subs, edge[j].second.second);
		if(x!=y){
			res.push_back(make_pair(edge[j].first, make_pair(edge[j].second.first, edge[j].second.second)));
			Union(subs,x,y);
			i++;
		}
		j++;
	}
	int total=0;
	for(int k=0; k<n-1; k++){
		cout<<"Weight: "<<res[k].first<<"\t"<<"Source: "<<res[k].second.first<<" Dest: "<<res[k].second.second<<endl; 
		total+=res[k].first;
	}
	cout<<"Total Weight: "<<total<<endl;
	return 0;
}

