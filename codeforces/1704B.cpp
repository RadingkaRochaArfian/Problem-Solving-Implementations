#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,x;
vector<ll>a;
void solve() {
    cin>>n>>x;
    a.resize(n);
    for(auto &x:a)cin>>x;
    ll mn=a[0];
    ll mx=a[0];
    ll ans=0;
    for(int i=1;i<n;i++){
        if(mn>a[i]){
            mn=a[i];
        }
        if(mx<a[i]){
            mx=a[i];
        }
        if(mx-mn>2*x){
            ans++;
            mn=mx=a[i];
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