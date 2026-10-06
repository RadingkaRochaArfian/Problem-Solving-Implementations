#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int m;
    cin>>m;
    vector<vector<int>>g(6);
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool can=true;
    for(int i=1;i<=5;i++){
        if(g[i].size()<2 || g[i].size()>2){
            can=true;
            break;
        }
        can=false;
    }
    cout<<(can?"WIN":"FAIL")<<endl;
}
int main() {
    int t;
    t=1;
    while(t--) {
        solve();
    }
}