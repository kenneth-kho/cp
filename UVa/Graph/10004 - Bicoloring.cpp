//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=945
//Simple bfs and coloring to determine whether the graph is bipartite, stop bfs when 2 adjacent node can't have different color
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
	int n,l;while(cin>>n,n){
		cin>>l;vector<vector<int>> V(n);
		int a,b;bool able=1;
		for(int i=0;i<l;i++){
			cin>>a>>b;V[a].push_back(b);
		}vector<int> color(n,-1);color[0]=0;
		queue<int> Q;Q.push(0);
		while(!Q.empty()&&able){
			int node=Q.front();Q.pop();
			for(int i=0;i<V[node].size();i++){
				if(color[V[node][i]]==-1){
					color[V[node][i]]=color[node]?0:1;
					Q.push(V[node][i]);
				}else if(color[V[node][i]]==color[node]){
					able=0;break;
				}
			}
		}if(!able)cout<<"NOT ";cout<<"BICOLORABLE.\n";
	}
}
