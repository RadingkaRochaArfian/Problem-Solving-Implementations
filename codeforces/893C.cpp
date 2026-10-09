#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
vector<vector<int>>g;
vector<int>c;
int n,m;
vector<bool>vis;
int dfs(int v){
    vis[v]=true;
    int cost=c[v];
    stack<int>st;st.push(v);
    while(!st.empty()){
        int x=st.top();st.pop();
        for(int y:g[x]){
            if(!vis[y]){
                vis[y]=true;
                cost=min(cost,c[y]);
                st.push(y);
            }
        }
    }
    return cost;
} 
void solve() {
    cin>>n>>m;
    c.clear();c.resize(n+1);
    g.clear();g.resize(n+1);
    vis.clear();vis.resize(n+1);
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(!vis[i])
        ans+=dfs(i);        
    }
    cout<<ans<<endl;
}
int main() {
    int t;
    t=1;
    while(t--) {
        solve();
    }
}