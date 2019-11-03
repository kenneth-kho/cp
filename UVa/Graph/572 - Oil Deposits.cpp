//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=513
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
char map[105][105];
int N,M;
int di[]={-1,1,0,0,-1,1,-1,1};
int dj[]={0,0,-1,1,1,1,-1,-1};
int bfs(){
	int ans=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]=='@'){
				queue<pair<int,int>> Q;
				Q.push(make_pair(i,j));
				while(!Q.empty()){
					pair<int,int> node = Q.front();Q.pop();
					map[node.first][node.second]='*';
					for(int i=0;i<8;i++){
						int nextI = node.first + di[i];
						int nextJ = node.second + dj[i];
						if(nextI<0||nextI>=N||nextJ<0||nextJ>=M)continue;
						if(map[nextI][nextJ]=='@')Q.push(make_pair(nextI,nextJ));
					}
				}ans++;
			}
		}
	}return ans;
}
int main(){
	while(cin>>N>>M,N){
		for(int i=0;i<N;i++){getchar();
			for(int j=0;j<M;j++){
				map[i][j]=getchar();
			}
		}cout<<bfs()<<'\n';
	}
}
