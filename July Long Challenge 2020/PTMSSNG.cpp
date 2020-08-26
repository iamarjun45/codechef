#include<bits/stdc++.h>
#define MOD 1000000007
#define MAXN 200005
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int x[4*MAXN], y[4*MAXN];
int n;
void solve(){
	cin>>n;
	int total=(4*n)-1;
	for(int i=0;i<total;i++){
		cin>>x[i]>>y[i];
	}
	// Sort x
	sort(x,x+total);
	// Sort y
	sort(y,y+total);
	// Currently dont know the answer
	int ansx=-1,ansy=-1;
	// Initialising currx as first element
	int currx=x[0],currAnsx=1;
	// Initialising curry as first element
	int curry=y[0],currAnsy=1;
	// Traversing every element
	for(int i=1;i<total;i++){
		if(x[i]==currx){
			currAnsx++;
		}else{
			if(currAnsx%2!=0){
				ansx=currx;
				break;
			}
			currx=x[i];
			currAnsx=1;
		}
	}
	// Still not found, then no doubt its the last element
	if(ansx==-1)
		ansx=x[total-1];
	// Traversing every element
	for(int i=1;i<total;i++){
		if(y[i]==curry){
			currAnsy++;
		}else{
			if(currAnsy%2!=0){
				ansy=curry;
				break;
			}
			curry=y[i];
			currAnsy=1;
		}
	}
	// Still not found, then no doubt its the last element
	if(ansy==-1)
		ansy=y[total-1];
	cout<<ansx<<" "<<ansy<<"\n";
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




