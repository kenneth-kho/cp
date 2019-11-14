//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=83
//Standard coin change problem, but multiply everything by 20 first
#include<iostream>
using namespace std;
int main(){
	int coins[]={2000,1000,400,200,100,40,20,10,4,2,1};
	long long dp[6001]={1};
	for(int i=0;i<11;i++){
		for(int j=coins[i];j<6001;j++){
			dp[j]+=dp[j-coins[i]];
		}
	}float a;
	while(cin>>a,a){
		printf("%6.2f%17lld\n",a,dp[(int)(a*20)]);
	}
}
