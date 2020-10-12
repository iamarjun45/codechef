#include<bits/stdc++.h>
#define MOD 998244353
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int getAns(int x,int y){
	int z=x^y;
	if(z<=1)
		return z;
	for(int i=31;i>=0;i--){
		if(z&(1<<i))
			return (1<<i);
	}
}
int dfs(vector<int> small,int len){
	if(len==1)
		return small[0];
	int ans=INT_MAX;
	for(int i=0;i<len;i++){
		vector<int> smallest;
		for(int j=0;j<len;j++){
			if(i==j)
				continue;
			smallest.push_back(small[j]);
		}
		ans=min(ans,getAns(small[i],dfs(smallest,len-1)));
	}
	return ans;
}
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	vector<vector<int>> allSubsets;
	for(int i=0;i<n;i++){
		vector<int> small;
		for(int j=i;j<n;j++){
			small.push_back(arr[j]);
			allSubsets.push_back(small);
		}
	}
	int ans=0;
	for(auto x:allSubsets){
		ans=(ans+dfs(x,x.size()))%MOD;
	}
	cout<<ans<<"\n";
	return 0;
}




