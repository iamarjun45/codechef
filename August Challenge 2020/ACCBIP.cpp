#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n,c,k;
int colors[3005];
int values[3005];
int dp[3005][3005];
int small[3005][3005];
vector<vector<int>> types;
int removeL(int num,int color){
	vector<int> small=types[color];
	for(auto &x:small){
		if(num==0)
			break;
		int remove=min(x,num);
		x-=remove;
		num-=remove;
	}
	int totalLines=0;
	for(auto x:small){
		totalLines+=x;
	}
	int ans=totalLines*(totalLines-1)*(totalLines-2)/6;
	for(auto x:small){
		ans-=x*(x-1)*(totalLines-x)/2;
		ans-=x*(x-1)*(x-2)/6;
	}
	return ans;
}
void solve(){
	memset(dp,0,sizeof(dp));
	memset(colors,0,sizeof(colors));
	memset(small,-1,sizeof(small));
	cin>>n>>c>>k;
	map<int,int> m[c];
	for(int i=0;i<n;i++){
		int input1,input2,input3;
		cin>>input1>>input2>>input3;
		colors[input3-1]++;
		m[input3-1][input1]++;
	}
	types=vector<vector<int>>(c);
	for(int i=0;i<c;i++){
		for(auto x:m[i])
			types[i].push_back(x.second);
		sort(types[i].begin(),types[i].end());
	}
	for(int i=0;i<c;i++) cin>>values[i];
	for(int i=1;i<=c;i++){
		small[0][i-1]=removeL(0,i-1);
		dp[i][0]=dp[i-1][0]+small[0][i-1];
	}
	for(int i=1;i<=c;i++){
		for(int j=1;j<=k;j++){
			if(small[0][i-1]==-1)
				small[0][i-1]=removeL(0,i-1);
			dp[i][j]=dp[i-1][j]+small[0][i-1];
			if(colors[i-1]<3 || values[i-1]>j)
				continue;
			for(int l=1;l<=colors[i-1];l++){
				int currentValue=values[i-1]*l;
				if(currentValue>j)
					break;
					if(small[l][i-1]==-1)
					small[l][i-1]=removeL(l,i-1);
				dp[i][j]=min(dp[i][j],dp[i-1][j-currentValue]+small[l][i-1]);	
			}
		}
	}
	cout<<dp[c][k]<<"\n";
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




