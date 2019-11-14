//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2512
//This is another variant of the knapsack problem. Of course, you can give the seller all your money,
//but you want to maximize the amount of money you can save. On the worst case, you'll have to pay
//price + largest denominator - 1, which is why we build dp array up to 20000.
#include<iostream>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int p,n,c[100],dp[20001]={1};cin>>p>>n;
		for(int i=0;i<n;i++)cin>>c[i];
		for(int i=0;i<n;i++){
			for(int j=20000;j>=c[i];j--){
				if(dp[j-c[i]]&&(dp[j]==0||dp[j]>dp[j-c[i]]+1))dp[j]=dp[j-c[i]]+1;
			}
		}while(dp[p]==0)p++;
		cout<<p<<' '<<dp[p]-1<<'\n';
	}
}
