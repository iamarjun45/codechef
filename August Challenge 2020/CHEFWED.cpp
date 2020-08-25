#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n,k;
int arr[1001];
void solve(){
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>arr[i];
	int dp[n];
	dp[0]=k;
	vector<vector<int>> freq(n,vector<int>(101,0));
	freq[0][arr[0]]++;
	for(int i=1;i<n;i++){
		if(freq[i-1][arr[i]]==0){
			dp[i]=dp[i-1];
			freq[i]=freq[i-1];
			freq[i][arr[i]]++;
		}else{
			if(freq[i-1][arr[i]]==1){
				dp[i]=dp[i-1]+2;
			}else{
				dp[i]=dp[i-1]+1;
			}
			freq[i]=freq[i-1];
			freq[i][arr[i]]++;
			int ans=dp[i];
			vector<int> ansFreq(100,0);
			vector<int> small(101,0);
			int collisions=0;
			for(int j=i;j>=0;j--){
				small[arr[j]]++;
				if(small[arr[j]]==2){
					collisions+=2;
				}else if(small[arr[j]]>2){
					collisions++;
				}
				if(j>0 && dp[j-1]+collisions+k<ans){
					ans=dp[j-1]+collisions+k;
					ansFreq=small;
				}
				if(j==0 && collisions+k<ans){
					ans=collisions+k;
					ansFreq=small;
				}
			}
			if(ans<dp[i]){
				dp[i]=ans;
				freq[i]=ansFreq;
			}
		}
	}
	cout<<dp[n-1]<<"\n";
	
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




