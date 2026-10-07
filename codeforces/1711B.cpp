#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
void solve() {
    cin>>n>>m;
    vector<ll>x(m+1),y(m+1),a(n+1),d(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>x[i]>>y[i];
        d[x[i]]++;
        d[y[i]]++;
    }  
    ll ans=INT_MAX;
    if(m%2==0)ans=0;
    for(int i=1;i<=n;i++){
        if(d[i]%2==1)ans=min(ans,a[i]);        
    }
    for(int i=1;i<=m;i++){
        if(d[x[i]]%2==0&&d[y[i]]%2==0)ans=min(ans,a[x[i]]+a[y[i]]);
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