#include<bits/stdc++.h>
#define MOD 998244353
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int m,n,q,k;
int arr[100005];

void solve(){
	cin>>m>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	int mat[m+1][n+1];
	mat[1][1]=arr[1];
	for(int i=2;i<=m;i++){
		mat[i][1]=(mat[i-1][1]*arr[1])%MOD;
	}
	for(int j=2;j<=n;j++){
		mat[1][j]=(mat[1][j-1]*arr[j])%MOD;
	}
	for(int i=2;i<=m;i++){
		for(int j=2;j<=n;j++){
			mat[i][j]=(((mat[i-1][j]+mat[i][j-1])%MOD)*arr[j])%MOD;
		}
	}
	while(q--){
		cin>>k;
		cout<<mat[k][n]<<"\n";
	}
}
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}




