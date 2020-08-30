#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long p;
		cin>>p;
		long long denominations[n];
		for(int i=0;i<n;i++){
			cin>>denominations[i];
		}
		long long k=p;
		long long solution[n]={0};
		for(int i=n-1;i>=0;i--){
			if(k%denominations[i]==0){
				solution[i]=(k/denominations[i])-1;
				k=k-solution[i]*denominations[i];
			}else{
				solution[i]=(k/denominations[i])+1;
				k=k-solution[i]*denominations[i];
				break;
			}
		}
		if(k<0){
			cout<<"YES ";
			for(int i=0;i<n;i++)
			cout<<solution[i]<<" ";
			cout<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
