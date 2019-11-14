//https://www.codechef.com/problems/MCO16303
//Recursively count all permutations (with memoization) that ends up between l and r
#include<iostream>
#include<cstring>
using namespace std;
int arr[501],memo[501][100001]={},n,l,r;
int dp(int idx,int sum){
	if(idx==n)return (sum>=l&&sum<=r);
	if(memo[idx][sum]!=-1)return memo[idx][sum];
	return memo[idx][sum]=(dp(idx+1,sum+arr[idx])+dp(idx+1,sum-arr[idx]))%1000000007;
}
int main(){
	cin>>n;for(int i=0;i<n;i++)cin>>arr[i];cin>>l>>r;
	memset(memo,-1,sizeof(memo));cout<<dp(0,0);
}
