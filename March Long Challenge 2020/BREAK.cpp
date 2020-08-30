#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
long long a[MAXN],b[MAXN];
int n,s;
void solve(){
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
	    cin>>b[i];
	}
	sort(b,b+n);
	unordered_set<long long> s;
	if(a[0]>=b[0]){
	    cout<<"NO"<<endl;
	    return;
	}
	s.insert(a[0]);
	s.insert(b[0]);
	for(int i=1;i<n;i++){
	    if(s.find(a[i])==s.end()){
	        cout<<"NO"<<endl;
	        return;
	    }
	    if(a[i]>=b[i]){
	        cout<<"NO"<<endl;
	        return;
	    }
	    s.insert(a[i]);
	    s.insert(b[i]);
	}
	cout<<"YES"<<endl;
}
int main(){
	int t;
	cin>>t>>s;
	while(t--){
		solve();
	}
}
