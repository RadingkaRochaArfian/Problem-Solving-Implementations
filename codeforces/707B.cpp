#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,k;
vector<int>ru,rv,rl;
vector<bool>storage;
void solve() {
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v,l;cin>>u>>v>>l;
        ru.push_back(u);
        rv.push_back(v);
        rl.push_back(l);
    }
    storage.assign(n+1,false);
    int min_cost=INT_MAX;
    for(int i=0;i<k;i++){
        int c;cin>>c;
        storage[c]=true;
    }
    for(int i=0;i<m;i++){
        int u=ru[i];
        int v=rv[i];
        int l=rl[i];
        if(storage[u]!=storage[v]){
            min_cost=min(min_cost,l);
        }
    }
    if(min_cost==INT_MAX){
        cout<<-1<<endl;
    }else{
        cout<<min_cost<<endl;
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}