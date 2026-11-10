#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<ll>p;
void solve() {
    cin>>n;
    p.assign(n+1,-1);
    for(ll i=1;i<=n;i++)cin>>p[i];
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ll x=i;
        ll d=0;
        while(x!=-1){
            x=p[x];
            d++;
        }
        ans=max(ans,d);
    }
    cout<<ans<<endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}