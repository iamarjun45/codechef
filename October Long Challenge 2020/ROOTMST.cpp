#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

class Edge{
	public:
		int src;
		int dest;
		int w;
};
bool compare(Edge e1,Edge e2){
    return e1.w<e2.w;
}
vector<Edge> allEdges;
vector<Edge> withOne;
unordered_set<int> s;
int n,m;
int findParent(int v,int*parent){
    if(parent[v]==v)
        return v;
    return findParent(parent[v],parent);
}

int kruskal(int include,int total){
	int parent[n];
	for(int i=0;i<n;i++) parent[i]=i;
	int ans=0;
	for(auto x:s){
		parent[withOne[x].dest]=0;
		ans=ans+withOne[x].w;
	}
	parent[withOne[include].dest]=0;
	ans=ans+withOne[include].w;
	int count=0;
	int i=0;
	while(count!=total-1){
		Edge currentEdge=allEdges[i];
		int sourceParent=findParent(currentEdge.src,parent);
        int destParent=findParent(currentEdge.dest,parent);
        if(sourceParent!=destParent){
            ans+=currentEdge.w;
            count++;
            parent[sourceParent]=destParent;
        }
        i++;
	}
	return ans;
}
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		Edge input;
		cin>>input.src>>input.dest>>input.w;
		input.src--;
		input.dest--;
		if(input.src==0){
			withOne.push_back(input);
		}else{
			allEdges.push_back(input);
		}
	}
	sort(allEdges.begin(),allEdges.end(),compare);
	vector<int> ans;
	for(int i=1;i<n;i++){
		int smallAns=INT_MAX;
		int curr=-1;
		for(int j=0;j<withOne.size();j++){
			if(s.find(j)==s.end()){
				int buildMST=kruskal(j,n-i);
				if(buildMST<smallAns){
					smallAns=buildMST;
					curr=j;
				}
			}
		}
		s.insert(curr);
		ans.push_back(smallAns);
	}
	for(auto x:ans){
		cout<<x<<" ";
	}
	cout<<"\n";
	return 0;
}




