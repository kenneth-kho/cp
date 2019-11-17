//https://www.codechef.com/problems/TASHIFT
//This is basically KMP matching string A into string B+B, and keep track
//of the longest common prefix thus far everytime a match is found
#include<iostream>
using namespace std;
char A[1000001];
char B[1000001];
int prefix[1000000]={};
int main(){
	int len,last=0,max=0,shift=0,p=1,i=0,j=0;
	cin>>len>>A>>B;
	while(p<len){
		if(A[p]==A[last])prefix[p++]=++last;
		else if(last!=0)last=prefix[last-1];
		else prefix[p++]=0;
	}while(j<len*2){
		if(A[i]==B[j<len?j:j-len]){
			i++,j++;
			if(max<i)max=i,shift=j-i;
		}else if(i>0)i=prefix[i-1];
		else j++;
	}cout<<shift<<'\n';
}
