#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<bool>vis;
vector<vector<ll>>adj;
vector<ll>x,y;
void dfs(ll start){
    stack<ll>st;
    st.push(start);
    vis[start]=true;
    while(!st.empty()){
        ll id=st.top();st.pop();
        vis[id]=true;
        for(auto x:adj[id]){
            if(!vis[x]){
                st.push(x);
                vis[x]=true;
            }
        }
    }
}
void solve() {
    cin>>n;
    vis.assign(n+1,false);
    adj.assign(n+1,vector<ll>());
    x.assign(n+1,0);
    y.assign(n+1,0);
    for(ll i=1;i<=n;i++){
        ll a,b;cin>>a>>b;
        x[i]=a;
        y[i]=b;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            if(x[i]==x[j]||y[i]==y[j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }
    cout<<ans-1<<endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}