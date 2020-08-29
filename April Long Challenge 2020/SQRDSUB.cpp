#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define MAXN 1000005
using namespace std;

int n;
int arr[MAXN];
void solve(){
	cin>>n;
	long long ans=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int prev=-1;
	int second_prev=-1;
	for(int start=0;start<n;start++){
		if(arr[start]%4==0){
			ans=ans+start+1;
			prev=start;
			second_prev=start;
		}else if(arr[start]%2==0){
			if(prev!=-1){
				int diff=start-prev;
				ans=ans+start+1;
				ans=ans-diff;
			}
			second_prev=prev;
			prev=start;
		}else{
			if(prev!=-1){
				ans=ans+(start-prev);
				if(second_prev!=-1){
					ans=ans+second_prev+1;
				}	
			}else{
				ans=ans+start+1;
			}
		}
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","r",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

