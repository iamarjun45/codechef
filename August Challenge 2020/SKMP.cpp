#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

string s,p;
void solve(){
	vector<int> freq(26,0);
	cin>>s>>p;
	int n=s.length();
	int m=p.length();
	for(auto x:s){
		freq[x-'a']++;
	}
	for(auto x:p){
		freq[x-'a']--;
	}
	string ans;
	int count=p[0]-'a';
	int i=0;
	while(i<m){
		int small=p[i]-'a';
		if(small<count){
			break;
		}
		if(small>count){
			count++;
			break;
		}
		i++;
	}
	for(int i=0;i<count;i++){
		char ch='a'+i;
		for(int j=0;j<freq[i];j++){
			ans=ans+ch;
		}
	}
	ans=ans+p;
	for(int i=count;i<26;i++){
		char ch='a'+i;
		for(int j=0;j<freq[i];j++){
			ans=ans+ch;
		}
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




