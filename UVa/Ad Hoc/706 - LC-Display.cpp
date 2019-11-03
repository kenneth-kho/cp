//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=647
#include<iostream>
using namespace std;
const char num[5][31]={
	" -     -  -     -  -  -  -  - ",
	"| |  |  |  || ||  |    || || |",
	"       -  -  -  -  -     -  - ",
	"| |  ||    |  |  || |  || |  |",
	" -     -  -     -  -     -  - "
};int main(){
	int n;string s;
	while(cin>>n>>s,n){
		for(int i=0;i<5*n;i+=((i/n)&1?1:n)){
			for(int j=0;j<s.length();j++){
				cout<<(j?" ":"")<<num[i/n][(s[j]-'0')*3];
				for(int k=0;k<n;k++)cout<<num[i/n][(s[j]-'0')*3+1];
				cout<<num[i/n][(s[j]-'0')*3+2];
			}cout<<'\n';
		}cout<<'\n';
	}
}
