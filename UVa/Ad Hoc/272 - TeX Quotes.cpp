//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=208
#include<iostream>
using namespace std;
int main(){
	bool a=0;char c;
	while((c=getchar())!=EOF){
		if(c=='\"')cout<<((a=1-a)?"``":"\'\'");
		else cout<<c;
	}
}
