#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
long long arr[MAXN];
long long n,q;
long long x1,x2,y;
void solve(){
    cin>>n>>q;
    for(long long i=1;i<=n;i++){
        cin>>arr[i];
    }
    while(q--){
        long long ans=0;
        cin>>x1>>x2>>y;
        for(int i=x1;i<x2;i++){
            long long a1=max(arr[i],arr[i+1]);
            long long a2=min(arr[i],arr[i+1]);
          if(a1>=y&&a2<=y)
          ans++;
        }
        cout<<ans<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
	return 0;
}

