#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
const ll maxn=1e2;
vector<ll>g[maxn+1];
vector<ll>deg;
vector<bool>vis(maxn);
ll bfs(){
    queue<ll>q;
    for(ll i=1;i<=n;i++){
        if(deg[i]==1){
            q.push(i);
        }
    }
    ll ans=0;
    while(!q.empty()){
        ll sz=q.size();
        vector<ll>cur;
        for(ll i=0;i<sz;i++){
            ll v=q.front();q.pop();
            if(!vis[v]&&deg[v]==1){
                cur.push_back(v);
            }
        }
        if(cur.empty())break;
        ans++;
        for(auto v:cur){
            vis[v]=true;
        }
        for(auto v:cur){
            for(auto u:g[v]){
                if(!vis[u]){
                    deg[u]--;
                    if(deg[u]==1){
                        q.push(u);
                    }
                }
            }
        }
    }
    return ans;
}
void solve() {
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        g[i].clear();
    }
    vis.assign(n+1,false);
    deg.assign(n+1,0);
    for(int i=0;i<m;i++){
        ll a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    cout<<bfs()<<endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}