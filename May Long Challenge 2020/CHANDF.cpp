#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int x,y,l,r;
void solve(){
	cin>>x>>y>>l>>r;
	if(x==0||y==0){
		cout<<l<<"\n";
		return;
	}
	int ans=0;
	int one=1;
	unordered_map<int,int> m;
	for(int i=40;i>=0;i--){
		if(x&(one<<i)){
			ans=ans|(one<<i);
			m[i]++;	
		}if(y&(one<<i)){
			ans=ans|(one<<i);
			m[i]++;	
		}		
	}
	if(ans>=l&&ans<=r){
		cout<<ans<<"\n";
	}else if(l==r){
		cout<<l<<"\n";
	}else if(r<ans){
		int i=40;
		for(;i>=0;i--){
			if(r>=(one<<i))
				break;
			if(ans&(one<<i))
				ans=ans-(one<<i);
		}
		while(ans>r){
			int gap=ans-r;
			int minJ=0;
			for(int j=0;j<=40;j++){
				if(gap>=(one<<j)){
					minJ=j;
				}
			}
			if(ans&(one<<minJ)){
				if(m[minJ]==1){
					ans=ans-(one<<minJ);
				}else{
					int total=(one<<minJ)*(one<<minJ);
					int minnJ=minJ+1;
					while((!(ans&(one<<minnJ)))&&minnJ<40){
						minnJ++;
					}
					if(minnJ!=40&&total>minnJ){
						ans=ans-(one<<minnJ);
					}else{
						ans=ans-(one<<minJ);
					}
				}
			}else{
				while(!(ans&(one<<minJ)))
					minJ++;
				ans=ans-(one<<minJ);
			}
		}
		cout<<ans<<"\n";
	}
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




