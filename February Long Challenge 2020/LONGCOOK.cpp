#include<bits/stdc++.h>
using namespace std;
int dayofweek(int d, long long m, long long y) 
{ 
static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
y -= m < 3; 
return ( y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7; 
}
bool leapyear(long long year){
	if(year%400==0)
	return true;
	if(year%4==0&&year%100!=0)
	return true;
	return false;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long m1,y1,m2,y2;
		cin>>m1>>y1;
		cin>>m2>>y2;
		if(m1>2){
			m1=2;
			y1++;
		}
		else{
			m1=2;
		}
		if(m2>=2){
			m2=2;
		}else{
			m2=2;
			y2--;
		}
		long long ans=0;
		long long small=(y2-y1)/400;
		ans=small*101;
		long long newYear=y1;
		if(small!=0)
		newYear+=small*400;
		int day=dayofweek(1,m1,newYear);
		for(long long i=newYear;i<=y2;i++){
		if(leapyear(i)){
		if(day==6)
		ans++;
		}
		else{
			if(day==6||day==0){
				ans++;
			}
		}
		if(leapyear(i))
		day=(day+2)%7;
		else
		day=(day+1)%7;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
