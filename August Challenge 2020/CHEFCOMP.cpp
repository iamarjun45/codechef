#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n;
vector<vector<int>> Graph;
int P[200005];
int A[200005];
int B[200005];
int days[200005];
bool visited[200005];
bool visited2[200005];
void dfs(int city,int day,int root){
	visited2[city]=true;
	for(auto x:Graph[city]){
		if(visited[x] || visited2[x])
			continue;
		dfs(x,day,root);
		if(B[x]==0) continue;
		B[x]-=min(A[root],B[x]);
		if(B[x]==0)
			days[x]=day;
	}
}
void solve(){
	memset(days,0,sizeof(days));
	memset(visited,0,sizeof(visited));
	cin>>n;
	Graph=vector<vector<int>>(n);
	for(int i=0;i<n-1;i++){
		int src,dest;
		cin>>src>>dest;
		src--;
		dest--;
		Graph[src].push_back(dest);
		Graph[dest].push_back(src);
	}
	for(int i=0;i<n;i++) cin>>P[i];
	for(int i=0;i<n;i++) cin>>A[i];
	for(int i=0;i<n;i++) cin>>B[i];
	for(int i=0;i<n;i++){
		int city=P[i]-1;
		visited[city]=true;
		if(B[city]!=0){
			B[city]-=min(A[city],B[city]);
			if(B[city]==0)
			days[city]=i+1;
		}
		memset(visited2,0,sizeof(visited2));
		dfs(city,i+1,city);
	}
	for(int i=0;i<n;i++){
		if(days[i]==0)
			cout<<"-1 ";
		else
			cout<<days[i]<<" ";
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




