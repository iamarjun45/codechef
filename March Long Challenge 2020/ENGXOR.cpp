#include<bits/stdc++.h>
#define MAXN 100006
using namespace std;
long long a[MAXN];
long long n,q,p,ans1,ans2;
void solve(){
    cin>>n>>q;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    long long odd=0,even=0;
    for(long long i=0;i<n;i++){
    	long long check=a[i];
        int count=0;
        while(check){
            count+=check&1;
            check>>=1;
        }
        if(count%2==0)
		even++;
		else
		odd++;
        }
    while(q--){
        cin>>p;
        long long check=p;
        int count=0;
        while(check){
            count+=check&1;
            check>>=1;
        }
        if(count%2==0)
        cout<<even<<" "<<odd<<"\n";
        else
        cout<<odd<<" "<<even<<"\n";
    }
}
int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}
