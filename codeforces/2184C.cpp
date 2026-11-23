#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;
void solve() {
    cin>>n>>k;
    ll ans=-1;
    for(ll i=0;i<=31;i++){
        ll p=1ll<<i;
        ll low=n/p;
        ll high=(n+p-1)/p;
        if(k==low||k==high){
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}