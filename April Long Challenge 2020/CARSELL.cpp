#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

int n;
void solve(){
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	sort(v.rbegin(),v.rend());
	ll ans=0;
	for(int i=0;i<n;i++){
		int x=max(v[i]-i,0);
		ans=(ans+x)%MOD;
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","r",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

