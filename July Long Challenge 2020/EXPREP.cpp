#include<bits/stdc++.h>
#define MOD 998244353
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

map<string,int> substrings;
map<string,int> subWeights;
int weight[26];
string s;
int n;
// Power function for Modulo Inverse
int power(int x,int n){
	if(n==0)
		return 1;
	int small=power(x,n/2);
	int ans=(small*small)%MOD;
	if(n%2==0)
		return ans;
	return (ans*x)%MOD;
}

void solve(){
	// 	Clear the maps please
	substrings.clear();
	subWeights.clear();
	// Input the string
	cin>>s;
	// Input the weights
	for(int i=0;i<26;i++){
		cin>>weight[i];
	}
	// 'n' is the length 
	n=s.length();
	// Calculate weight for each substring
	for(int i=0;i<n;i++){
		string curr;
		int currWeight=0;
		for(int j=i;j<n;j++){
			curr=curr+s[j];
			currWeight=currWeight+weight[s[j]-'a'];
			substrings[curr]++;
			subWeights[curr]=currWeight;
		}
	}
	// Total substrings
	int total=n*(n+1)/2;
	// Denominator a^(-1)=a^(MOD-2)
	int denominator=power(total,MOD-2);
	int numerator=0;
	// For each subtring,
	for(auto x:substrings){
		string curr=x.first;
		string prefix;
		int subPowers=0;
		// Try for each prefix
		for(int i=0;i<curr.length();i++){
			prefix=prefix+curr[i];
			bool okay=true;
			int k=0;
			for(int j=i+1;j<curr.length();j++){
				if(prefix[k]!=curr[j]){
					okay=false;
					break;
				}
				if(k==i)
					k=0;
				else
					k++;
			}
			// If okay, then add please
			if(okay)
				subPowers=(subPowers+subWeights[prefix])%MOD;
		}
		// Total numerator for this substring = count*power
		numerator=(numerator+(x.second*subPowers)%MOD)%MOD;
	}
	// Finally P*Q^(-1)
	int ans=(numerator*denominator)%MOD;
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




