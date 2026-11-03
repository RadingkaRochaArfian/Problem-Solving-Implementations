#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
unordered_map<string,vector<string>>g;
ll dfs(string data){
    ll res=0;
    for(auto v:g[data]){
        res=max(res,dfs(v));
    }
    return res+1;
}
void solve() {
    cin>>n;
    for(int i=0;i<n;i++){
        string n1,x,n2;cin>>n1>>x>>n2;
        for(auto &c:n1)c=tolower(c);
        for(auto &c:n2)c=tolower(c);
        g[n1].push_back(n2);
    }
    ll ans=0;
    for(auto &[k,v]:g){
        ans=max(ans,dfs(k));
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