//https://www.codechef.com/problems/FLAASH
//Calculate and memoize the minimum time between going down 1 step, down to n/2, or down to n/3 (when possible)
#include<iostream>
using namespace std;
long long dp[1000002]={0,0};
int main(){
	for(int i=2;i<1000001;i++){
		if(i%6==0)dp[i]=min(min(dp[i/2],dp[i/3]),dp[i-1])+1;
		else if(i%3==0)dp[i]=min(dp[i/3],dp[i-1])+1;
		else if(i%2==0)dp[i]=min(dp[i/2],dp[i-1])+1;
		else dp[i]=dp[i-1]+1;
	}int t;cin>>t;
	while(t--){
		int n;cin>>n;
		cout<<dp[n]<<'\n';
	}
}
