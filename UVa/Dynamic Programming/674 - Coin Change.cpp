//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=615
//Protip: count the combination, not the permutation
#include<iostream>
using namespace std;
int main(){
	int dp[7500];for(int i=0;i<7500;i++)dp[i]=1;
	for(int i=5;i<7500;i++)dp[i]+=dp[i-5];
	for(int i=10;i<7500;i++)dp[i]+=dp[i-10];
	for(int i=25;i<7500;i++)dp[i]+=dp[i-25];
	for(int i=50;i<7500;i++)dp[i]+=dp[i-50];
	int a;while(cin>>a){cout<<dp[a]<<'\n';}
}
