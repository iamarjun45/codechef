#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n;
vector<int> A;
void gogo() {
    unordered_set<int> s;
    set<int> t;
    for (int i : A) {
        set<int> r;
        r.insert(i);
        for (int j : t) r.insert(i | j);
        t = r;
        for (int j : t) s.insert(j);
    }
    if(s.size()==(n*(n+1)/2)){
    	cout<<"YES\n";
	}else{
		cout<<"NO\n";
	}
}
void solve(){
	cin>>n;
	A=vector<int>(n);
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	gogo();
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




