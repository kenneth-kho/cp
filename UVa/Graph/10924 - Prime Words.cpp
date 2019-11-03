//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1865
#include<iostream>
using namespace std;
int main(){
	string s;
	while(getline(cin,s)){
		int prime=1,total=0;
		for(int i=0;i<s.length();i++){
			if(s[i]>='a'&&s[i]<='z')total+=s[i]-'a'+1;
			else total+=s[i]-'A'+27;
		}for(int i=2;i<total;i++)if(total%i==0)prime=0;
		cout<<(prime?"It is a prime word.\n":"It is not a prime word.\n");
	}
}
