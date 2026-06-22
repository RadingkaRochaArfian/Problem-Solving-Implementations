#include<stdio.h>
typedef long long ll;
#define MAX 1000000
 
ll s1[MAX];
ll s2[MAX];
int main(){
	ll n;scanf("%lld",&n);
	ll total=n*(n+1)/2;
	if(total%2==1){
		printf("NO\n");
		return 0;
	}
	ll halve=total/2;
	ll i1=0,i2=0;
	for(ll i=n;i>=1;i--){
		if(i<=halve){
			s1[i1]=i;
			halve-=i;
			i1++;	
		}else{
			s2[i2]=i;
			i2++;
		}
	}
	printf("YES\n");
	printf("%lld\n",i1);
	for(ll i=0;i<i1;i++){
		printf("%lld ",s1[i]);
	}
	printf("\n%lld\n",i2);
	for(ll i=0;i<i2;i++){
		printf("%lld",s2[i]);
		if(i<i2-1){
			printf(" ");
		}
	}
}