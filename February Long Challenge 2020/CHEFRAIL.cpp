#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> xr;
		vector<int> xl;
		vector<int> yu;
		vector<int> yd;
		unordered_map<long,int> searchx;
		unordered_map<long,int> searchy;
		bool ans1=true;
		int countx=0;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			if(a==0){
				ans1=false;
				countx++;
				continue;
			}
			if(a>0)
			xr.push_back(a);
			else
			xl.push_back(a);
			searchx[(long long)a*a]++;
		}
		int county=0;
		for(int i=0;i<m;i++){
			int a;
			cin>>a;
			if(a==0){
				ans1=false;
				county++;
				continue;
			}
			if(a>0)
			yu.push_back(a);
			else
			yd.push_back(a);
			searchy[(long long)a*a]++;
		}
		long long ans=0;
		for(int i=0;i<xr.size();i++){
			for(int j=0;j<xl.size();j++){
				int distance=xr[i]-xl[j];
				long long search=(((long long)distance*distance)-((long long)xr[i]*xr[i])-((long long)xl[j]*xl[j]))/2;
				ans+=searchy[search];
			}
		}
		for(int i=0;i<yu.size();i++){
			for(int j=0;j<yd.size();j++){
				int distance=yu[i]-yd[j];
				long long search=(((long long)distance*distance)-((long long)yu[i]*yu[i])-((long long)yd[j]*yd[j]))/2;
				ans+=searchx[search];
			}
		}
		if(!ans1){
			ans+=(n-countx)*(m-county);
		}
		cout<<ans<<endl;
	}
	return 0;
}
