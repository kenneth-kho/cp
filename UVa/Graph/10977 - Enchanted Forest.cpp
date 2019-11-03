//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1918
//Use map to store blocked positions as 1, including positions inside jigglypuffs' circle of loudness
//The circle centered at (x,y) includes all points (xi,yi) where (x-xi)^2 + (y-yi)^2 <= L^2
//The rest is just simple bfs
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int R,C;
int map[205][205]={};
int vis[205][205]={};
int dr[]={-1,1,0,0};
int dc[]={0,0,-1,1};
int bfs(int fromR,int fromC,int toR,int toC){
	if(map[fromR][fromC]==1)return -1;
	queue<pair<int,int>> Q;
	Q.push(make_pair(fromR,fromC));
	for(int moves=0,s;s=Q.size();moves++){
		while(s--){
			pair<int,int> node=Q.front();Q.pop();
			if(vis[node.first][node.second])continue;
			vis[node.first][node.second]=1;
			if(node.first==toR&&node.second==toC)return moves;
			for(int j=0;j<4;j++){
				int nextR=node.first+dr[j];
				int nextC=node.second+dc[j];
				if(nextR<1||nextR>R)continue;
				if(nextC<1||nextC>C)continue;
				if(map[nextR][nextC]==1)continue;
				Q.push(make_pair(nextR,nextC));
			}
		}
	}return -1;
}
int main(){
	while(cin>>R>>C,R){
		memset(map,0,sizeof(map));
		memset(vis,0,sizeof(vis));
		int m;cin>>m;
		for(int i=0;i<m;i++){
			int r,c;cin>>r>>c;
			map[r][c]=1;
		}int n;cin>>n;
		for(int i=0;i<n;i++){
			int r,c,L;cin>>r>>c>>L;
			for(int nr=max(r-L,1);nr<=min(r+L,R);nr++){
				for(int nc=max(c-L,1);nc<=min(c+L,C);nc++){
					if((r-nr)*(r-nr)+(c-nc)*(c-nc)<=L*L){
						map[nr][nc]=1;
					}
				}
			}
		}int ans=bfs(1,1,R,C);
		if(ans==-1)cout<<"Impossible.\n";
		else cout<<ans<<'\n';
	}
}
