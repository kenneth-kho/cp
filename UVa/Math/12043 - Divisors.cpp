//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3194
//This can be solved using naïve method, nothing special
#include<iostream>
#define ll long long
using namespace std;
ll d(ll n){ll tot=0,i=1;
	for(;i*i<=n;i++){
		if(n%i==0)tot+=2;
	}if(n==--i*i)tot--;return tot;
}ll s(ll n){ll tot=0,i=1;
	for(;i*i<=n;i++){
		if(n%i==0)tot+=i+n/i;
	}if(n==--i*i)tot-=i;return tot;
}int main(){
	ll n;cin>>n;while(n--){
		ll a,b,k,count=0,sum=0;cin>>a>>b>>k;
		for(ll i=(a+k-1)/k*k;i<=b;i+=k){
			count+=d(i);sum+=s(i);
		}cout<<count<<' '<<sum<<'\n';
	}
}
