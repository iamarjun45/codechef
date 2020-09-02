#include<bits/stdc++.h>
using namespace std;
int n;
string s;
void solve(){
	cin>>n;
	cin>>s;
	int x=0,y=0;
	for(int i=0;i<n;i++){
		if(i!=0){
			if(s[i]=='L'||s[i]=='R'){
				if(s[i-1]=='L'||s[i-1]=='R')
				continue;
			}else{
				if(s[i-1]=='U'||s[i-1]=='D')
				continue;
			}
		}
		if(s[i]=='L'){
			x=x-1;
		}else if(s[i]=='R'){
		    x=x+1;	
		}else if(s[i]=='U'){
			y=y+1;
		}else{
			y=y-1;
		}
	}
	cout<<x<<" "<<y<<"\n";
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

