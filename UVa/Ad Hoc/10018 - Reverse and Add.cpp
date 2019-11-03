//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=959
#include<iostream>
using namespace std;
int main(){
	int t;cin>>t;while(t--){
		long long n,count=0;cin>>n;
		while(1){
			long long a=0,b=n;
			while(b){
				a=a*10+b%10;
				b/=10;
			}if(n==a)break;
			count++;n+=a;
		}cout<<count<<' '<<n<<'\n';
	}
}
