//https://www.codechef.com/problems/HACKS
//Solution to the linear diophantine equation ax + by = c exists only if c is a multiple of gcd(a,b)
//The minimum positive c would be gcd(fib(a),fib(b)) = fib(gcd(a,b))
#include<iostream>
using namespace std;
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
unsigned long long fib(int n){
	if(n==0)return 0;
	unsigned long long a=0,b=1,c;
	for(int i=1;i<n;i++){
		c=a+b;a=b;b=c;
	}return b;
}
int main(){
	int n;cin>>n;
	while(n--){
		int i,j;cin>>i>>j;
		cout<<fib(gcd(i,j))<<'\n';
	}
}
