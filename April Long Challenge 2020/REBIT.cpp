#include<bits/stdc++.h>
#define MOD 998244353
#define ll long long
using namespace std;

string l;
int x[4][4]={{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};
int a[4][4]={{0,0,0,0},{0,1,2,3},{0,2,2,0},{0,3,0,3}};
int o[4][4]={{0,1,2,3},{1,1,1,1},{2,1,2,1},{3,1,1,3}};
ll power(ll x,ll count){
	if(count==0){
		return 1;
	}
	ll small=power(x,count/2);
	if(count%2==0){
		ll ans=(small*small)%MOD;
		return ans;
	}
	ll ans=(x*((small*small)%MOD))%MOD;
	return ans;
}
void solve(){
	cin>>l;
	stack<char> op;
	stack<vector<ll> >operands;
	ll count=0;
	for(int i=0;i<l.length();i++){
		if(l[i]=='('){
			op.push(l[i]);
		}else if(l[i]=='#'){
			vector<ll> small(4,1);
			count++;
			operands.push(small);
		}else if(l[i]==')'){
			while(op.top()!='('){
				char ch=op.top();
				op.pop();
				vector<ll> ans(4,0);
				vector<ll> first=operands.top();
				operands.pop();
				vector<ll> second=operands.top();
				operands.pop();
				if(ch=='^'){
					for(int i=0;i<4;i++){
						for(int j=0;j<4;j++){
							ans[x[i][j]]=(ans[x[i][j]]+(first[i]*second[j])%MOD)%MOD;
						}
					}
				}else if(ch=='|'){
					for(int i=0;i<4;i++){
						for(int j=0;j<4;j++){
							ans[o[i][j]]=(ans[o[i][j]]+(first[i]*second[j])%MOD)%MOD;
						}
					}
				}else if(ch=='&'){
					for(int i=0;i<4;i++){
						for(int j=0;j<4;j++){
							ans[a[i][j]]=(ans[a[i][j]]+(first[i]*second[j])%MOD)%MOD;
						}
					}
				}
				operands.push(ans);
			}
			op.pop();
		}else{
			op.push(l[i]);
		}
	}
	vector<ll> ans=operands.top();
	ll den=power(4,count);
	ll in=power(den,MOD-2);
	for(int i=0;i<4;i++){
		ans[i]=(ans[i]*in)%MOD;
		cout<<ans[i]<<" ";
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

