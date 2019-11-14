//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=167
//This is a standard longest decreasing subsequence problem
#include<iostream>
using namespace std;
int main(){
	int n,tc=0;
	while(cin>>n,n!=-1){
		int arr[100005]={n};n=0;
		while(arr[n]!=-1)cin>>arr[++n];
		int dp[100005]={};
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(arr[j]<arr[i]&&dp[j]<dp[i]+1)dp[j]=dp[i]+1;
			}
		}int ans=0;for(int i=0;i<n;i++)ans=max(ans,dp[i]);
		if(tc)printf("\n");printf("Test #%d:\n",++tc);
        printf("  maximum possible interceptions: %d\n",ans+1);
	}
}
