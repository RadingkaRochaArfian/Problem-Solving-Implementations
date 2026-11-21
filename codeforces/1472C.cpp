#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<ll>a,dp;
void solve() {
    cin>>n;
    a.assign(n+1,0);dp.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll ans=0;
    for(int i=n;i>=1;i--){
        ll next=a[i]+i;
        if(next<=n){
            dp[i]=a[i]+dp[next];
        }else{
            dp[i]=a[i];
        }
        ans=max(ans,dp[i]);
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