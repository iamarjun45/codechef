#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int test;
	cin>>test;
	for(int i=0;i<test;i++){
	    int n;
	    cin>>n;
	    long long a[n],b[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>b[i];
	    }
	    sort(a,a+n);
	    sort(b,b+n);
	    long long ans=0;
	    for(int i=0;i<n;i++){
	        ans+=min(a[i],b[i]);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}

