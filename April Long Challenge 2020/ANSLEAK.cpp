#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

int n,m,k;
void solve(){
	cin>>n>>m>>k;
	int maxOf=(n/m)+1;
	map<int,int> count;
	for(int i=0;i<n;i++){
		map<int,int> search;
		for(int j=0;j<k;j++){
			int a;
			cin>>a;
			search[a]++;
		}
		int max=-1;
		for(int i=1;i<=m;i++){
			if((max==-1)||(search[i]>search[max])){
				if(count[i]<maxOf){
					max=i;
				}
			}
		}
		count[max]++;
		cout<<max<<" ";
	}
	cout<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","r",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

