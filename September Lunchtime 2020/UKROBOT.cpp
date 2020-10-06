#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int r,c;
void solve(){
	cin>>r>>c;
	string s="U";
	for(int i=1;i<c;i++)
		s=s+'R';
	cout<<s<<"\n";
}
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t=1;
	while(t--){
		solve();
	}
	return 0;
}




