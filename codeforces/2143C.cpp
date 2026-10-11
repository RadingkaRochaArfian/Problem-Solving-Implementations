#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int>g[n+1];
    vector<int>deg(n+1);
    for(int i=1;i<=n-1;i++){
        int u,v,x,y;cin>>u>>v>>x>>y;
        if(x>y){
            g[v].push_back(u);
            deg[u]++;
        }else{
            g[u].push_back(v);
            deg[v]++;
        }
    }
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(deg[i]==0){
            q.push(i);
        }
    }
    vector<int>p(n+1);
    for(int i=1;i<=n;i++){
        int u=q.front();q.pop();
        p[u]=i;
        for(auto adj:g[u]){
            deg[adj]--;
            if(deg[adj]==0){
                q.push(adj);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<p[i]<<' ';
    }
    cout<<endl;
}
int main(){
    int t;
    t=1;
    cin>>t;
    while (t--){
        solve();
    }
}