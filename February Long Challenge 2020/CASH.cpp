#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;long long k;
		cin>>n>>k;
		long long a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		long long rightSum[n];
		for(int i=0;i<n;i++){
			long long ans=a[i]%k;
			rightSum[i]=ans;
		}
		long long leftSum[n];
		for(int i=0;i<n;i++){
			if(rightSum[i]!=0)
			leftSum[i]=k-rightSum[i];
			else
			leftSum[i]=0;
		}
		for(int i=1;i<n;i++){
			rightSum[i]+=rightSum[i-1];
		}
		for(int i=n-2;i>=0;i--){
			leftSum[i]+=leftSum[i+1];
		}
		if(leftSum[0]==0){
			cout<<0<<endl;
			continue;
		}
		long long ans=rightSum[n-1];
		for(int i=n-2;i>=0;i--){
			long long smallAns=rightSum[i]-leftSum[i+1];
			if(smallAns<0)
			break;
			if(smallAns<ans)
			ans=smallAns;
		}
		cout<<ans<<endl;
	}
	return 0;
}
