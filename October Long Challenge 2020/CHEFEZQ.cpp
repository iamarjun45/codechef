#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n,k;
int arr[100005];
void solve(){
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int leftOver=0;
	for(int i=0;i<n;i++){
		if(arr[i]+leftOver<k){
			cout<<i+1<<"\n";
			return;
		}
		leftOver=(arr[i]+leftOver-k);
	}
	int days = n + leftOver/k + 1;
	cout<<days<<"\n";
}
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}




