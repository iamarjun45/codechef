#include<bits/stdc++.h>
using namespace std;
long long solve(int arr[][4],bool visitedi[],bool visitedj[],int p){
	long long ans=0;
	for(int i=0;i<4;i++){
		if(visitedi[i])
		continue;
		visitedi[i]=true;
		bool ans1=true;
		for(int j=0;j<4;j++){
			if(visitedj[j])
			continue;
			if(arr[i][j]!=0){
				ans1=false;
				visitedj[j]=true;
				ans=max(ans,arr[i][j]*p+solve(arr,visitedi,visitedj,p-25));
				visitedj[j]=false;
			}
		}
		if(ans1)
		ans-=100;
		visitedi[i]=false;
	}
	return ans;
}
int main(){
	int t;
	cin>>t;
	long long sum=0;
	while(t--){
		int n;
		cin>>n;
		int arr[4][4];
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				arr[i][j]=0;
			}
		}
		for(int i=0;i<n;i++){
			char ch;int time;
			cin>>ch>>time;
			arr[ch-'A'][(time/3)-1]++;
		}
		long long solution=0;
		bool visitedi[4]={0};
		bool visitedj[4]={0};
		for(int i=0;i<4;i++){
			bool ans=true;
			for(int j=0;j<4;j++){
				if(arr[i][j]!=0)
				ans=false;
			}
			if(ans){
				solution-=100;
				visitedi[i]=true;
			}
		}
		solution+=solve(arr,visitedi,visitedj,100);
		cout<<solution<<endl;
		sum+=solution;
	}
	cout<<sum<<endl;
	return 0;
}
