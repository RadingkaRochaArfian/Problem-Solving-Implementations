#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
void solve() {
    cin>>n>>m;
    vector<ll>cnt(n+1);
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        cnt[u]++;
        cnt[v]++;
    }
    map<int,int>mp;
    for(int i=1;i<=n;i++){
        mp[cnt[i]]++;
    }
    vector<ll>cat;
    for(auto p:mp){
        cat.push_back(p.second);
    }
    sort(cat.begin(),cat.end());
    if(cat.size()==3){
        cout<<cat[1]<<' '<<cat[2]/cat[1]<<endl;
    }else{
        cout<<cat[0]-1<<' '<<cat[1]/(cat[0]-1)<<endl;
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}