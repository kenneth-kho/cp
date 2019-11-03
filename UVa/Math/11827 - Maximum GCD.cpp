//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2927
//Simple, just iterate through all pairs and find the highest gcd using Euclid's algorithm
#include<iostream>
#include<sstream>
using namespace std;
int gcd(int a,int b){while(b)b^=a^=b^=a%=b;return a;}
int main(){
	int n;cin>>n>>ws;
	while(n--){
		string s;getline(cin,s);
		istringstream in(s);
		int arr[200]={},x=0,maks=0;
		while(in>>arr[x++]);
		for(int i=0;i<x-2;i++)
			for(int j=i+1;j<x-1;j++)
				if(gcd(arr[i],arr[j])>maks)
					maks=gcd(arr[i],arr[j]);
		cout<<maks<<'\n';
	}
}
