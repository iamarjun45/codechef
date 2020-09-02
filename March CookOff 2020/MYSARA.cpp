#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n;
int arr[50005];
void solve(){
	cin>>n;
	long long ans=1;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(i!=0&&arr[i]<arr[i-1])
		ans=0;
	}
	if(ans==0){
		cout<<ans<<endl;
		return;
	}
	long long l=1;
	for(int i=1;i<n;i++){
		int ok=arr[i-1]&arr[i];
		int ones=__builtin_popcount(ok);
		ans=(ans*((l<<ones)%MOD))%MOD;
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
