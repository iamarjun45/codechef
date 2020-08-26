#include<bits/stdc++.h>
#define MOD 998244353
#define int long long
using namespace std;

int power(int x,int n){
	if(n==0)
		return 1;
	int small=power(x,n/2);
	int ans=(small*small)%MOD;
	if(n%2==0)
		return ans;
	ans=(ans*x)%MOD;
	return ans;
}

int n,x;
int arr[100005];
void solve(){
	cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int t=n*(n+1);
	int p=power(arr[0],t);
	int total=1;
	int curr=1;
	for(int i=1;i<n;i++){
		curr=(curr*x)%MOD;
		total=(total+curr)%MOD;
		int small=power(total,n-i);
		p=(p*((small*small)%MOD))%MOD;
	}
	cout<<p<<"\n";
}
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}




