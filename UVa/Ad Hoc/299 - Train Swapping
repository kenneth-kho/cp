//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=235
#include<iostream>
using namespace std;
int main(){
	int t;cin>>t;while(t--){
		int n,count=0;cin>>n;
		int arr[60]={};
		for(int i=0;i<n;i++)cin>>arr[i];
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n-i-1;j++){
				if(arr[j]>arr[j+1]){
					swap(arr[j],arr[j+1]);
					count++;
				}
			}
		}cout<<"Optimal train swapping takes "<<count<<" swaps.\n";
	}
}
