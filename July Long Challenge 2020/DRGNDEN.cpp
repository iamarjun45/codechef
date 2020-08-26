#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,q;
int arr[200005];
int value[200005];
int query(int start,int end){
	if(start<=end){
		if(arr[start]<=arr[end] && start!=end)
			return -1;
		int ans=value[end];
		int high=arr[end];
		for(int i=end-1;i>start;i--){
			if(arr[i]>high && arr[i]<arr[start]){
				ans+=value[i];
				high=arr[i];
			}else if(arr[i]>=arr[start]){
				return -1;
			}
		}
		if(start!=end)
			ans=ans+value[start];
		return ans;
	}else{
		if(arr[start]<=arr[end] && start!=end)
			return -1;
		int ans=value[end];
		int high=arr[end];
		for(int i=end+1;i<start;i++){
			if(arr[i]>high && arr[i]<arr[start]){
				ans+=value[i];
				high=arr[i];
			}else if(arr[i]>=arr[start]){
				return -1;
			}
		}
		if(start!=end)
			ans=ans+value[start];
		return ans;
	}
}
void solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		cin>>value[i];
	}
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int idx,change;
			cin>>idx>>change;
			value[idx]=change;
		}else{
			int start,end;
			cin>>start>>end;
			int ans=query(start,end);
			cout<<ans<<"\n";
		}
	}
}
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}




