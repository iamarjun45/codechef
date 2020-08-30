#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[56];
void solve(){
	map<int,int> search;
	map<int,bool> search1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		search1[arr[i]]=true;
	}
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		search[arr[i]]+=a;
	}
	int min=INT_MAX;
	for(int i=1;i<=m;i++){
		if(!search1[i])
		continue;
		int maybe=search[i];
		if(maybe<min)
		min=maybe;
	}
	cout<<min<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
