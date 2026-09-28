#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
const ll maxn=1e6;
ll power(ll base,ll exp){
    ll res=1;
    base%=mod;
    while(exp>0){
        if(exp%2==1)res=(res*base)%mod;
        base=(base*base)%mod;
        exp/=2;
    }
    return res;
}
ll pow3[maxn+1];
ll pow9[maxn+1];
ll inv8=power(8ll,mod-2);

void precompute(){
    pow3[0]=1;
    pow9[0]=1;
    for(int i=1;i<=maxn;i++){
        pow3[i]=(pow3[i-1]*3)%mod;
        pow9[i]=(pow9[i-1]*9)%mod;
    }
}
ll solve(){
    ll n;
    cin>>n;
    ll pow3n=pow3[n];
    ll pow9n=pow9[n];
    ll sum=(pow9n-1+mod)%mod;
    sum=(3*sum)%mod;
    sum=(sum*inv8)%mod;
    sum=(1+sum)%mod;
    sum=(pow3n*sum)%mod;
    return sum;
}
int main(){
    precompute();
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Kasus #"<<i<<": "<<solve()<<endl;
    }
}