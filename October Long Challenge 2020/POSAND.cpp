#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==1){
			cout<<"1"<<endl;
		}else if(__builtin_popcount(n)==1){
			cout<<"-1"<<endl;
		}else{
			int ans[n];
			ans[0]=2;
			ans[1]=3;
			ans[2]=1;
			for(int i=4;i<=n;i++){
				if( __builtin_popcount(i)==1){
					ans[i-1]=i+1;
					ans[i]=i;
					i=i+1;
				}else{
					ans[i-1]=i;
				}
			}
			for(int i=0;i<n;i++) cout<<ans[i]<<" ";
			cout<<endl;
		}
	}
	return 0;
}




