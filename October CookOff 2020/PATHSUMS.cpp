#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


int n;
vector<vector<int>> Graph;
vector<bool> visited;
vector<int> ans;
void dfs(int i=0,int color=1){
	ans[i]=color;
	visited[i]=true;
	for(auto x:Graph[i]){
		if(visited[x])
			continue;
		if(color==1)
			dfs(x,color+1);
		else
			dfs(x,color-1);
	}
}
void solve(){
	cin>>n;
	Graph=vector<vector<int>>(n);
	visited=vector<bool>(n,0);
	ans=vector<int>(n,0);
	for(int i=0;i<n-1;i++){
		int l,r;
		cin>>l>>r;
		Graph[l-1].push_back(r-1);
		Graph[r-1].push_back(l-1);
	}
	dfs();
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
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




