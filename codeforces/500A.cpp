#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n,t;cin>>n>>t;
    vector<ll>a(n+1);
    a[n]=1;
    for(ll i=1;i<n;i++)cin>>a[i];
    for(ll i=1;i<=n;i+=a[i]){
        if(i==t){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}