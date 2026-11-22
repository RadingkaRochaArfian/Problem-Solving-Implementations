#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
void solve() {
    cin>>n;
    vector<ll> vis(n+1),p(n+1),dp(n+1),blk(n+1);
    for(int i=1;i<=n;i++){
        vis[i]=0;
        cin>>p[i];
    }
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        blk[i]=s[i-1]=='0';
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        vector<ll>c;
        ll v=i;
        while(!vis[v]){
            vis[v]=1;
            c.push_back(v);
            v=p[v];
        }
        ll sum=0;
        for(auto x:c){
            sum+=blk[x];
        }
        for(auto x:c){
            dp[x]=sum;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<' ';
    }
    cout<<endl;
    
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}