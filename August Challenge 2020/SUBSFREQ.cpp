#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n;
int arr[500005];
int fact[500005];
int inv[500005];
int abcd[500005];
int power(int a,int b){
    if(b==0)
        return 1;
    int small=power(a,b/2);
    int ans=(small*small)%MOD;
    if(b%2==0){
        return ans;
    }else{
        return (ans*a)%MOD;
    }
}
int NcR(int a,int b){
	int small=(((fact[a]*inv[b])%MOD)*inv[a-b])%MOD;
	return small;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) arr[i]=0;
	for(int i=0;i<n;i++){
		int input;
		cin>>input;
		arr[input]++;
	}
	bool okay=true;
	for(int i=1;i<=n && okay;i++){
		if(arr[i]!=1)
			okay=false;
	}
	if(okay){
		vector<int> ans(n);
		ans[0]=1;
		for(int i=1;i<n;i++)
			ans[i]=(ans[i-1]*2)%MOD;
		for(int i=n-1;i>=0;i--)
			cout<<ans[i]<<" ";
		cout<<"\n";
		return;
	}
	vector<int> efgh(n+5,1);
	vector<int> iklm(n+5,1);
	for(int i=1;i<=n;i++){
		if(arr[i]==0) continue;
		int total=1;
		for(int j=1;j<=arr[i];j++){
			total=(total+NcR(arr[i],j))%MOD;
			efgh[j]=(efgh[j]*total)%MOD;
		}
		iklm[arr[i]+1]=(iklm[arr[i]+1]*total)%MOD;
	}
	int ans=1;
	int i=1;
	while(i<=n){
		ans=(ans*iklm[i])%MOD;
		efgh[i]=(efgh[i]*ans)%MOD;
		i++;
	}
	i=1;
	while(i<=n){
		int small=0,total=1;
		int j=1;
		while(j<=arr[i]){
			int abc,def;
			abc=def=NcR(arr[i],j);
			total=(total+abc)%MOD;
		    efgh[j]=(efgh[j]*power(total,MOD-2))%MOD;
			abc=(abc*efgh[j])%MOD;
			int ghi=total-def+MOD;
			efgh[j]=(efgh[j]*ghi)%MOD;
			small=(small+abc)%MOD;
			j++;
		}
		cout<<small<<" ";
		i++;
	}
	cout<<"\n";
}
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	fact[0]=1;
	fact[1]=1;
	abcd[0]=1;
	abcd[1]=1;
	int m=MOD;
	for(int i=2;i<=500000;i++){
		fact[i]=(fact[i-1]*i)%MOD;
		abcd[i]=((m-(m/i))*abcd[m%i])%m;
	}
	inv[0]=1;
	inv[1]=1;
	for(int i=2;i<=500000;i++){
		inv[i]=(abcd[i]*inv[i-1])%m;
	}
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}




