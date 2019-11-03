//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=473
//Simple bfs, but you can move in 3 directions
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int L,R,C;
pair<int,pair<int,int>> S;
char map[33][33][33];
char visited[33][33][33];
int di[]={-1,1,0,0,0,0};
int dj[]={0,0,-1,1,0,0};
int dk[]={0,0,0,0,-1,1};
int bfs(){
    queue<pair<int,pair<int,int>>> Q;Q.push(S);
    for(int moves=0,s;s=Q.size();moves++){
        while(s--){
            pair<int,pair<int,int>> node = Q.front();Q.pop();
            if(visited[node.first][node.second.first][node.second.second])continue;
            visited[node.first][node.second.first][node.second.second]=1;
            if(map[node.first][node.second.first][node.second.second]=='E')return moves;
            for(int i=0;i<6;i++){
                int nextI=node.first+di[i],nextJ=node.second.first+dj[i],nextK=node.second.second+dk[i];
                if(nextI<0||nextI>=L||nextJ<0||nextJ>=R||nextK<0||nextK>=C)continue;
                if(map[nextI][nextJ][nextK]!='#'&&!visited[nextI][nextJ][nextK])Q.push(make_pair(nextI,make_pair(nextJ,nextK)));
            }
        }
    }return -1;
}int main(){
    while(cin>>L>>R>>C,L){getchar();
        for(int i=0;i<L;i++){
            for(int j=0;j<R;j++){
                for(int k=0;k<C;k++){
                	visited[i][j][k]=0;
                    map[i][j][k]=getchar();
                    if(map[i][j][k]=='S')S=make_pair(i,make_pair(j,k));
                }getchar();
            }getchar();
        }int ans=bfs();
        if(ans==-1)cout<<"Trapped!\n";
        else cout<<"Escaped in "<<ans<<" minute(s).\n";
    }
}
