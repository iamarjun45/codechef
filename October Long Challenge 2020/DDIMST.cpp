#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

vector<vector<int>> arr(200005);
vector<vector<int>> all(200005);
vector<int> parent(200005);
vector<int> found;
vector<int> position;
int n,d;

class Edge{
	public:
		int src;
		int dest;
		int w;
};
void dfs(int i,int j=0,int sum=0){
	if(j==d){
		all[i].push_back(sum);
		return;
	}
	dfs(i,j+1,sum+arr[i][j]);
	dfs(i,j+1,sum-arr[i][j]);
}
void findMax(){
	found=vector<int>(all[0].size(),LLONG_MIN);
	position=vector<int>(all[0].size(),0);
	for(int i=1;i<=n;i++){
		int k=0;
		for(auto x:all[i-1]){
			if(x>=found[k]){
				found[k]=x;
				position[k]=i;
			}
			k++;
		}
	}
}
vector<Edge> finalAns;
bool compare(Edge &e1,Edge &e2){
	return e1.w>e2.w;
}
int findParent(int v){
	if(v==parent[v])
		return v;
	return findParent(parent[v]);
}
void solve(){
	cin>>n>>d;
	for(int i=0;i<n;i++){
		for(int j=0;j<d;j++){
			int input;
			cin>>input;
			arr[i].push_back(input);
		}
	}
	for(int i=0;i<n;i++) dfs(i);
	findMax();
	for(int i=1;i<=n;i++){
		for(int j=0;j<all[0].size();j++){
			if(position[j]!=i){
				Edge input;
				input.src=i;
				input.dest=position[j];
				input.w=found[j]-all[i-1][j];
				finalAns.push_back(input);
			}
		}
	}
	sort(finalAns.begin(),finalAns.end(),compare);
	for(int i=1;i<=n;i++) parent[i]=i;
	int count=0;
	int ans=0;
	int i=0;
	while(count!=n-1){
		Edge currentEdge=finalAns[i];
		int sourceParent=findParent(currentEdge.src);
        int destParent=findParent(currentEdge.dest);
        if(sourceParent!=destParent){
        	parent[sourceParent]=destParent;
        	ans=ans+currentEdge.w;
        	count++;
		}
		i++;
	}
	cout<<ans<<"\n";
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




