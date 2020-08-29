#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define MAXN 1000001
using namespace std;

int n;
int arr[MAXN];
void pre(){
	for(int i=1;i<MAXN;i++){
		arr[i]=i;
	}
}
void solve(){
	cin>>n;
	if(n>3)
	cout<<n/2<<"\n";
	else
	cout<<1<<"\n";
	if(n<=3){
		cout<<n<<" ";
		for(int i=1;i<=n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	cout<<"3 1 2 3\n";
	for(int i=4;i<=n;i+=2){
		if(i+1<=n){
			cout<<2<<" "<<arr[i]<<" "<<arr[i+1]<<"\n";
		}else{
			cout<<1<<" "<<arr[i]<<"\n";
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","r",stdout);
	pre();
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

