#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
        cin>>n;
        int maxi=INT_MIN;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>maxi)
                maxi=arr[i];
        }
        vector<int> s;
        for(int i=0;i<n;i++){
            if(arr[i]==maxi){
                s.push_back(i);
            }
        }
    int k=s.size();
        int f=s[0];
        int l=s[k-1];
        int mid=n/2;
        int ans=0;
        if(f>=mid&&l>=mid){
            ans=n-l;
            ans+=f-(n/2);
        }
        else if(f<mid){
            int h=mid-f;
            if((l+h)<=n-1)
                ans=n-(l+h);
            else
                ans=0;
        }

        cout<<ans<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
