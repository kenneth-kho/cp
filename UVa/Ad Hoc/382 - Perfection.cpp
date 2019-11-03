//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=318
#include<iostream>
using namespace std;
int main(){
	cout<<"PERFECTION OUTPUT\n";
	while(1){
		int n;cin>>n;if(n==0)break;
		printf("%5d  ",n);
		int p=0,sum=0;if(n==1)p=1;
		for(int i=1;i<n;i++){
			if(n%i==0)sum+=i;
		}if(sum==n)cout<<"PERFECT\n";
		else if(sum>n)cout<<"ABUNDANT\n";
		else cout<<"DEFICIENT\n";
	}cout<<"END OF OUTPUT\n";
}
