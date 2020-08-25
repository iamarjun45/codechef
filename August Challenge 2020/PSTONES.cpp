#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n,k;
int arr[101];
int edges;
void solve(){
	cin>>n>>k;
	for(int i=0;i<n-1;i++){
		int u,v,value;
		cin>>u>>v>>value;
		arr[u-1]=value-1;
	}
	edges=n-1;
	for(int i=0;i<n;i++){
		map<int,bool> m1;
		for(int start=0;start<=edges;start++){
			int end=start+i;
			if(end>=n)
				break;
			if(start==0 && end<edges){
				int small=1<<arr[end];
				m1[small]=true;
			}else if(end==edges && start-1>=0){
				int small=1<<arr[start-1];
				m1[small]=true;
			}else if(start-1>=0 && end<edges){
				if(arr[start-1]==arr[end]){
					int small=1<<arr[start-1];
					m1[small]=true;
				}
				else{
					int small=(1<<arr[start-1])+(1<<arr[end]);
					m1[small]=true;
				}
			}else{
				m1[0]=true;
			}
		}
		int total=(1<<k);
		for(int i=0;i<total;i++){
			cout<<m1[i];
		}
		cout<<"\n";
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




