#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,x;
int arr[100005];
void solve(){
	cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int i=0;
	int ans=0;
	while(i<n){
		if(arr[i]==x){
			while(i<n && arr[i]==x){
				ans++;
				i++;
			}
			x=x*2;
		}else if(arr[i]<x){
			while((i+1<n) && (arr[i+1]<=x)){
				i++;
				ans++;
			}
			if(arr[i]==x){
				ans++;
				x=2*x;
				i++;
			}
			else if(i==n-1 || ((2 * arr[i]) < x)){
				i++;
				ans++;
			}else{
				ans++;
				x=2*arr[i];
				i++;
			}
		}else{
			while(arr[i] >= (2*x)){
				x=2*x;
				ans++;
			}
			if(arr[i]==x){
				x=2*x;
				ans++;
				i++;
			}else{
				if(i==n-1){
					ans+=2;
					i++;
				}else{
					if(arr[n-1] >= (2*x)){
						ans+=2;
						x=arr[i]*2;
						i++;
					}else{
						ans+=n-i+1;
						break;
					}
				}
			}
		}
	}
	cout<<ans<<"\n";
}
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}




