#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n;
map<int,int> firstArray;
map<int,int> secondArray;
map<int,int> totalCount;
void solve(){
    // Clear all the maps
	firstArray.clear();
	secondArray.clear();
	totalCount.clear();
	cin>>n;
	// It will store the minimum element
	int smallest=INT_MAX;
	// Taking first array input
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		smallest=min(data,smallest);
		firstArray[data]++;
		totalCount[data]++;
	}
	// Taking second array input
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		smallest=min(data,smallest);
		secondArray[data]++;
		totalCount[data]++;
	}
	for(auto x:totalCount){
	    // Count of frequency of some element is odd
		if(x.second%2!=0){
			cout<<"-1\n";
			return;
		}
		// Each array should contain half elements
		int half=x.second/2;
		// If both the array contains half elements
		if(firstArray[x.first]==half){
			firstArray[x.first]=0;
			secondArray[x.first]=0;
		}
		// If firstArray contains more elements
		else if(firstArray[x.first]>half){
			firstArray[x.first]=firstArray[x.first]-half;
			secondArray[x.first]=0;
		}
		// If secondArray contains more elements
		else{
			firstArray[x.first]=0;
			secondArray[x.first]=secondArray[x.first]-half;
		}
	}
	// Size of vector
	int k=0;
	vector<pair<int,int>> tobeswapped;
	// Increasing order
	for(auto x:firstArray){
		for(int i=0;i<x.second;i++){
			tobeswapped.push_back(make_pair(x.first,0));
			k++;
		}
	}
	// Decreasing order
	for(auto x:secondArray){
		for(int i=0;i<x.second;i++){
			tobeswapped[--k].second=x.first;
		}
	}
	// Swapping condition
	int ans=0;
	for(auto x:tobeswapped){
		ans=ans+min(2*smallest,min(x.first,x.second));
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
		solve();
	}
	return 0;
}




