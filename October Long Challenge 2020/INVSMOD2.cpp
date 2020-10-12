#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int getAns(int i){
	int smallAns=i*((3*i)-1);
	smallAns=smallAns/2;
	return smallAns;
}
int get(int a){
	a=a%2;
	if(a<0)
		return 1;
	return a;
}
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int last=n-1;
		int small = !(k & last);
		for(int i=1;1;i++){
			int smallAns=getAns(i);
			if(smallAns > k){
				cout<<small<<"\n";
				break;
			}
			int temp=k-smallAns;
			int first = !((temp-i) & last);
			int second = !(temp & last);
			small = ((k >= smallAns + i) ? (i%2==0 ? (get(small+first)) : (get(small-first))) : small);
			small = ((k >= smallAns) ? (i%2==0 ? (get(small+second)) : (get(small-second))) : small);
		}
	}
	return 0;
}



 
