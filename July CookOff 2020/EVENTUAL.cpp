#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	    string s;
	    cin>>n>>s;
	    vector<int> freq(26,0);
	    for(int i=0;i<n;i++){
	        freq[s[i]-'a']++;
	    }
	   
	    for(int i=0;i<freq.size();i++){
	        if(freq[i]%2!=0){
	            cout<<"NO\n";
	            return;
	        }
	    }
	        cout<<"YES\n";
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
