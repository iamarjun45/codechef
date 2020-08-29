#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

ll x,k;
void solve(){
	cin>>x>>k;
	ll total=0;
	while(x%2==0){
		total++;
		x=x/2;
	}
	for(ll i=3;i*i<=x;i=i+2){
		while(x%i==0){
			total++;
			x=x/i;
		}
	}
	if(x>2)
	total++;
	if(total<k){
		cout<<"0\n";
	}else{
		cout<<"1\n";
	}
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
	return 0;
}

