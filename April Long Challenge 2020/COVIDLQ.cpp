#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","r",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        vector<int>v;
        for(int i=0;i<n;i++){
            if(arr[i]==1)
                v.push_back(i);
        }
        bool flag=true;
        for(int i=0;i<v.size()-1;i++){
            if(v[i+1]-v[i]<6){
                flag=false;
                cout<<"NO"<<endl;
                break;
            }
        }
        if(flag)
            cout<<"YES"<<endl;
    }
}
