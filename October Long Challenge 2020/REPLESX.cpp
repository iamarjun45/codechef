#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

bool solve1(vector<int> & input,int p,int x){
	if(input[p]==x){
		cout<<"0"<<endl;
		return true;
	}
	return false;
}
void solve2(vector<int> & input,int p,int k,int x){
	int ans=-1;
	if(k>=p && input[p]>=x){
		int i=p;
		for(;i>=0 && input[i]>x;i--);
		ans=p-i;
	}
	else if(k<=p && input[p]<=x){
		int i=p;
		for(;i<input.size() && input[i]<x;i++);
		ans=i-p;
	}
	cout<<ans<<"\n";
}
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,x,p,k;
		cin>>n>>x>>p>>k;
		vector<int> input(n);
		for(auto &y:input)
			cin>>y;
		sort(input.begin(),input.end());
		bool ans1=solve1(input,p-1,x);
		if(ans1) continue;
		solve2(input,p-1,k-1,x);
	}
	return 0;
}



