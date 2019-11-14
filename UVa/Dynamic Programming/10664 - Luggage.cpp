//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1605
//Here, I write a greedy solution which surprisingly got AC, but obviously not optimal.
//This greedy solution iterates from the largest element down to the smallest element and adds it if possible.
//A counter example would be 2 4 6 6 7 9, the optimal answer should be YES, 9+6+2 and 7+6+4.
//For the optimal DP solution, check out my UVa 562 - Dividing Coins solution, which is similar to this problem:
//https://github.com/kenneth-kho/cp/blob/master/UVa/Dynamic%20Programming/562%20-%20Dividing%20Coins.cpp
#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;
int main(){
	int n;cin>>n>>ws;while(n--){
		int arr[25],i=0,sum=0,curr=0;
		string s;getline(cin,s);
		istringstream in(s);
		while(in>>arr[i])
			sum+=arr[i++];
		sort(arr,arr+i);
		while(i--)
			if((curr+arr[i])*2<=sum)curr+=arr[i];
		cout<<(curr*2==sum?"YES\n":"NO\n");
	}
}
