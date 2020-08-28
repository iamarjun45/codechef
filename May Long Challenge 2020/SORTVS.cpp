#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n,m;
int arr[20];
int graph[20][20];
bool hasPath(vector<bool>visited,int start,int end){
    if(graph[start][end]==1)
        return true;
    visited[start]=true;
    for(int i=1;i<=n;i++){
        if(i==start)
            continue;
        if(graph[start][i]==1&&(!visited[i])){
            bool ans=hasPath(visited,i,end);
            if(ans)
                return true;
        }
    }
    return false;
}
void solve(){
	cin>>n>>m;
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			graph[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		graph[x][y]=1;
		graph[y][x]=1;
	}
	vector<pair<int,int> >v;
	int count=0;
	for(int i=1;i<=n;i++){
		int j=i;
		for(;j<=n;j++){
			if(arr[j]==i)
				break;
		}
		if(j==i)
			continue;
		swap(arr[j],arr[i]);
		v.push_back(make_pair(i,j));
		count++;
	}
	for(int i=0;i<v.size();i++){
		vector<bool>visited(n+1,0);
		if(hasPath(visited,v[i].first,v[i].second))
			count--;
	}
	cout<<count<<"\n";
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




