//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=503
//This is basically just a simple knapsack to find the maximum number of coins that is less than or equal the half of total coins
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n,sum=0;cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
			sum+=arr[i];
		}int dp[sum/2+1];memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			for(int j=sum/2;j>0;j--){
				if(j>=dp[j-arr[i]]+arr[i])dp[j]=max(dp[j],dp[j-arr[i]]+arr[i]);
			}
		}cout<<sum-dp[sum/2]*2<<'\n';
	}
}
