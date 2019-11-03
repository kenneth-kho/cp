//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3671
//Simple binary exponentiation O(log p)
#include<iostream>
#define ll long long
using namespace std;
int main(){
	int n;cin>>n;
	while(n--){
		ll b,p,m,r=1;cin>>b>>p>>m;
		while(p){
			if(p%2)r=r*b%m;
			p/=2;
			b=b*b%m;
		}cout<<r<<'\n';
	}
}
