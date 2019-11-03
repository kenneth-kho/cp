//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1081
//Find all the primes using segmented sieve (first calculate primes from 1 to √b, then from a to b),
//then iterate through all the primes
#include<iostream>
#define ll long long
using namespace std;
bool base[50000]={};
bool high[1000005]={};
int main(){
	ll a,b;
	while(cin>>a>>b){base[1]=1;
		for(ll i=2;i*i<=b;i++){
			if(!base[i]){
				for(ll j=i+i;j<50000;j+=i)base[j]=1;
				for(ll j=(i-a%i)%i;j<=b-a;j+=i)high[j]=1;
			}
		}ll min=-1,max=-1,p=-1,q=-1,r=-1,s=-1,last;
		for(ll i=a;i<=b;i++){
			if(p==-1){
				if(i<50000){
					if(!base[i])p=r=i;
				}else{
					if(!high[i-a])p=r=i;
				}
			}else if(q==-1){
				if(i<50000){
					if(!base[i])q=s=i;
				}else{
					if(!high[i-a])q=s=i;
				}min=max=q-p;last=q;
			}else{
				if(i<50000){
					if(!base[i]){
						if(i-last<min){
							p=last;q=i;min=i-last;
						}if(i-last>max){
							r=last;s=i;max=i-last;
						}last=i;	
					}
				}else{
					if(!high[i-a]){
						if(i-last<min){
							p=last;q=i;min=i-last;
						}if(i-last>max){
							r=last;s=i;max=i-last;
						}last=i;
					}
				}
			}
		}if(q==-1)cout<<"There are no adjacent primes.\n";
		else cout<<p<<','<<q<<" are closest, "<<r<<','<<s<<" are most distant.\n";
		for(int i=0;i<50000;i++)base[i]=0;
		for(int i=0;i<=b-a;i++)high[i]=0;
	}
}
