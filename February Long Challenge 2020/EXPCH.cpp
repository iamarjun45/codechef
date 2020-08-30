#include<bits/stdc++.h>
using namespace std;
long gcdExtended(long a, long b, long *x, long *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
    long x1, y1;
    long gcd = gcdExtended(b%a, a, &x1, &y1); 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
long modInverse(long a, long m) 
{ 
    long x, y; 
    long g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        return -1;
    else
    { 
        long res = (x%m + m) % m; 
        return res;
    } 
} 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		long long q=n*(n+1)/2;
		long long inv=modInverse(q,1000000007);
		long long change=0;
		for(int i=0;i<n;i++){
			int smallChange=0;
			int nc=0,no=0;
			for(int j=i;j<n;j++){
				if(s[j]=='('){
				    no++;
				}else if(s[j]==')'){
					if(no==nc){
						smallChange++;
						no++;
					}else{
						nc++;
					}
				}
				change=change+smallChange;
			}
		}
		change=(change*inv)%1000000007;
		cout<<change<<endl;
	}
	return 0;
}
