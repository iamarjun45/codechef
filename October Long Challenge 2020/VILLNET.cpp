#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;

int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int x,y,targetX,targetY;
		cin>>x>>y>>targetX>>targetY;
		int ans=0;
		queue<pair<int,int>> pendingNodes;
		queue<int> smallAns;
		pendingNodes.push({x,y});
		smallAns.push(0); 
		while(!pendingNodes.empty()){
			pair<int,int> front=pendingNodes.front();
			int small=smallAns.front();
			if(front.first==targetX && front.second==targetY){
				cout<<small<<"\n";
				break;
			}
			pendingNodes.pop();
			smallAns.pop();
			pendingNodes.push({front.first+(2*front.second),front.second});
			smallAns.push(small+1);
			pendingNodes.push({front.first-(2*front.second),front.second});
			smallAns.push(small+1);
			if(front.second+(2*front.first)>0)
				pendingNodes.push({front.first,abs(front.second+(2*front.first))});
			else
				pendingNodes.push({-front.first,abs(front.second+(2*front.first))});
			smallAns.push(small+1);
			if(front.second-(2*front.first)>0)
				pendingNodes.push({front.first,abs(front.second-(2*front.first))});
			else
				pendingNodes.push({-front.first,abs(front.second-(2*front.first))});
			smallAns.push(small+1);
		}
	}
	return 0;
}




