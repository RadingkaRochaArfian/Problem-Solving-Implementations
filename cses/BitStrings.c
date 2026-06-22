#include<stdio.h>
 
#define ll long long
 
ll pew(ll n){
	if(n==0)return 1;
	if(n==1)return 2;	
	ll sum=0;
	sum+=pew(n/2);
	sum=(sum*sum)%1000000007;
	if(n%2==1)sum=(sum*2)%1000000007;
	return sum;
}
 
int main(){
	ll n;scanf("%lld",&n);printf("%lld\n",pew(n));
}