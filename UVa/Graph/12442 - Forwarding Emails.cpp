//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3873
//I use O(n) dfs with memoization, because there are overlapping subproblems, 
//i.e. when traversing 2 -> 3 -> 1 -> 10 -> 3, we know sending to 2 can reach 4 martians (including self), 
//but in the process we also know sending to 3 can reach 3 martians, sending to 1 can reach 2 martians, etc.
#include<iostream>
using namespace std;
int adj[50001],vis[50001],dp[50001];
int dfs(int i){
	int res=1;
	vis[i]=1;
	if(!vis[adj[i]])res=dfs(adj[i])+1;
	vis[i]=0;
	return dp[i]=res;
}
int main(){
	int tt;cin>>tt;
	for(int t=1;t<=tt;t++){
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			int x,y;cin>>x>>y;
			adj[x]=y,vis[i]=dp[i]=0;
		}int max=0,ans;
		for(int i=1;i<=n;i++){
			if(dp[i]==0)dfs(i);
			if(dp[i]>max)max=dp[i],ans=i;
		}printf("Case %d: %d\n",t,ans);
	}
}
