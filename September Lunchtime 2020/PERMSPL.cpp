#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n;
int arr[101];
vector<int> a1;
vector<int> a2;
int actual_merge1(int f,int l)
{
    int mid=(l+f)/2;
     int inv_count=0;
    int i=f,j=mid+1;
    int x=0;
    int input1[l-f+1];
    while(i<=mid&&j<=l)
    {
        if(a1[i]<a1[j])
        {
            input1[x]=a1[i];
            i++;
            x++;
        }
        else
        {
            input1[x]=a1[j];
            j++;
            x++;
            inv_count=inv_count+(mid-i+1);

        }
    }
    while(i<=mid)
    {
        input1[x]=a1[i];
        x++;
        i++;
    }
    while(j<=l)
    {
        input1[x]=a1[j];
        x++;
        j++;
    }
    j=0;
    for(i=f; i<=l; i++)
    {
        a1[i]=input1[j++];
    }
    
    return inv_count;
}

int merge_sort1(int f,int l)
{
    int inv_count=0;
    if(f<l)
    {
        int mid=(f+l)/2;
        inv_count=inv_count+(merge_sort1(f,mid));
        inv_count=inv_count+(merge_sort1(mid+1,l));
        inv_count=inv_count+(actual_merge1(f,l));
    }
    return inv_count;
}
int actual_merge2(int f,int l)
{
    int mid=(l+f)/2;
     int inv_count=0;
    int i=f,j=mid+1;
    int x=0;
    int input1[l-f+1];
    while(i<=mid&&j<=l)
    {
        if(a2[i]<a2[j])
        {
            input1[x]=a2[i];
            i++;
            x++;
        }
        else
        {
            input1[x]=a2[j];
            j++;
            x++;
            inv_count=inv_count+(mid-i+1);

        }
    }
    while(i<=mid)
    {
        input1[x]=a2[i];
        x++;
        i++;
    }
    while(j<=l)
    {
        input1[x]=a2[j];
        x++;
        j++;
    }
    j=0;
    for(i=f; i<=l; i++)
    {
        a2[i]=input1[j++];
    }
    
    return inv_count;
}

int merge_sort2(int f,int l)
{
    int inv_count=0;
    if(f<l)
    {
        int mid=(f+l)/2;
        inv_count=inv_count+(merge_sort2(f,mid));
        inv_count=inv_count+(merge_sort2(mid+1,l));
        inv_count=inv_count+(actual_merge2(f,l));
    }
    return inv_count;
}
bool countInversions(){
	int count1=merge_sort1(0,a1.size()-1);
	int count2=merge_sort2(0,a2.size()-1);
	return count1==count2;
}
bool dfs(int i){
	if(i==n){
		vector<int> temp1=a1;
		vector<int> temp2=a2;
		if(countInversions())
			return true;
		a1=temp1;
		a2=temp2;
		return false;
	}
	a1.push_back(arr[i]);
	bool ans=dfs(i+1);
	a1.pop_back();
	if(ans==true)
		return true;
	a2.push_back(arr[i]);
	ans=dfs(i+1);
	a2.pop_back();
	return ans;
}
void solve(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	if(dfs(0))
		cout<<"YES\n";
	else
		cout<<"NO\n";
}
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}




