#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt(ll lo,ll hi,ll target,ll p){
    ll lo_rem=lo%p;
    ll diff=((target-lo_rem)%p+p)%p;
    ll first=lo+diff;
    if(first>hi)return 0;
    return (hi-first)/p+1;
}
void solve() {
    ll a,b,r1,c1,r2,c2;
    cin>>a>>b>>r1>>c1>>r2>>c2;
    ll p=a+b;
    ll k=a/2;
    ll ans=0;
    for(ll dr=0;dr<a;dr++){
        ll rdis=abs(dr-k);
        if(rdis>k)continue;
        ll cdismx=k-rdis;
        for(ll dc=0;dc<a;dc++){
            ll cdis=abs(dc-k);
            if(cdis>cdismx)continue;
            if((dr+dc)%2!=k%2)continue;
            ans+=cnt(r1,r2,dr,p)*cnt(c1,c2,dc,p);
        }
    }
    cout<<ans<<endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}