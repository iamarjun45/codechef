#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define MAXN 1000001
using namespace std;

int n,q;
int cost[100005];
vector<int> prime;
void sieve(){
	vector<bool> isPrime(MAXN,true);
	isPrime[0]=false;
	isPrime[1]=false;
	for(int i=2;i*i<=MAXN;i++){
		if(isPrime[i]==true){
			prime.push_back(i);
            for(int j=i*i;j<=MAXN;j+=i){
                isPrime[j]=false;
            }
        }
	}
}
void query(vector<int> path){
	map<int,ll> m;
	for(int i=0;i<path.size();i++){
	        int c=cost[path[i]];
		for(int j=0;j<prime.size();j++){
			if(c==1)
				break;
			while(c>1 && c%prime[j]==0){
				if(m.find(prime[j])!=m.end())
					m[prime[j]]++;
				else
					m.insert(make_pair(prime[j],1));
				c=c/prime[j];
			}
		}
		if(c!=1){
			if(m.find(c)!=m.end())
				m[c]++;
			else
				m.insert(make_pair(c,1));
		}
	}
	map<int,ll>::iterator it;
	ll ans=1;
	for(it=m.begin();it!=m.end();++it)
		ans=(ans*((*it).second+1))%MOD;
	cout<<ans<<"\n";
}
void getPath(vector<int> edges[],int src,int dest,vector<int>&path){
	if(src==dest){
		path.push_back(src);
		return;
	}
	bool visited[n]={0};
	queue<int>pendingVertices;
    map<int,int> store;
    visited[src]=true;
    pendingVertices.push(src);
    while(!pendingVertices.empty()){
        int currentVertex=pendingVertices.front();
        pendingVertices.pop();
        for(int i=0;i<edges[currentVertex].size();i++){
            if((!visited[edges[currentVertex][i]])){
                store[edges[currentVertex][i]]=currentVertex;
                if(dest==edges[currentVertex][i]){
                    int curr=edges[currentVertex][i];
                    path.push_back(curr);
                    while(curr!=src){
                        curr=store[curr];
                        path.push_back(curr);
                    }
                    return;
                }
                visited[edges[currentVertex][i]]=true;
                pendingVertices.push(edges[currentVertex][i]);
            }
        }
    }
}
void solve(){
	cin>>n;
	vector<int> edges[n];
	for(int i=0;i<n-1;i++){
		int f,s;
		cin>>f>>s;
		edges[f-1].push_back(s-1);
		edges[s-1].push_back(f-1);
	}
	for(int i=0;i<n;i++){
		cin>>cost[i];
	}
	cin>>q;
	for(int i=0;i<q;i++){
		int f,s;
		cin>>f>>s;
		vector<int> path;
		getPath(edges,f-1,s-1,path);
		query(path);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","r",stdout);
	sieve();
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}

