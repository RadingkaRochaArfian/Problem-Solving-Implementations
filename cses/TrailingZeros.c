#include<stdio.h>
#define ll long long
#define max 1000000007
ll findZero(ll n){
	ll sum=n/5;
	for(int i=25;i<max;i*=5){
		if(n>=i){
			sum+=n/i;
		}
	}
	return sum;
}
 
int main(){
	ll n;scanf("%lld",&n);printf("%lld\n",findZero(n));
}