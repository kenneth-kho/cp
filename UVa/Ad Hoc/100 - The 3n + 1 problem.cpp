//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=36
#include<iostream>
using namespace std;
int main(){
	int n,m;while(cin>>n>>m){
		int maks=0;for(int i=min(n,m);i<=max(n,m);i++){
			int a=i,count=1;
			while(a!=1){
				if(a%2==1)a=3*a+1;
				else a/=2;
				count++;
			}maks=max(maks,count);
		}cout<<n<<' '<<m<<' '<<maks<<'\n';
	}
}
