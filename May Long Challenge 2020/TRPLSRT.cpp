#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n,k;
unordered_map<int,int> m;
void solve(){
	cin>>n>>k;
	m.clear();
	bool visited[n+1]={0};
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(a==i){
			visited[i]=true;
			continue;
		}
		m[a]=i;
	}
	if(m.size()==0){
		cout<<"0\n";
		return;
	}
	vector<pair<int,int> >v;
	vector<vector<int> > ans;
	for(int i=1;i<=n;i++){
		if(visited[i])
			continue;
		visited[i]=true;
		vector<int> small;
		int y=m[i];
		while(y!=i){
			visited[y]=true;
			small.push_back(y);
			y=m[y];
		}
		small.push_back(i);
		int size=small.size();
		if(size==2){
			v.push_back(make_pair(small[0],small[1]));
			continue;
		}
		for(int i=2;i<size;i+=2){
			vector<int> ans1;
			ans1.push_back(small[i]);
			ans1.push_back(small[i-1]);
			ans1.push_back(small[i-2]);
			ans.push_back(ans1);
		}
		if(size%2==0)
		v.push_back(make_pair(small[size-1],small[size-2]));
	}
	if(v.size()%2!=0){
		cout<<"-1\n";
		return;
	}
	for(int i=0;i<v.size();i+=2){
		pair<int,int> first=v[i];
		pair<int,int> second=v[i+1];
		vector<int> small(3);
		small[0]=first.first;
		small[1]=first.second;
		small[2]=second.first;
		ans.push_back(small);
		small[0]=first.first;
		small[1]=second.second;
		small[2]=second.first;
		ans.push_back(small);		
	}
	if(ans.size()>k){
		cout<<"-1\n";
		return;
	}
	cout<<ans.size()<<"\n";
	for(auto x:ans){
		cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\n";
	}
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




