#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin>>n;
    vector<string>g(n);
    for(auto &it:g)cin>>it;
    vector<int>p(n);
    iota(p.begin(),p.end(),0);
    sort(p.begin(),p.end(),
    [&](int x,int y){
        if(g[x][y]=='1')return x<y;
        else return x>y;
    });
    for(auto x:p)cout<<x+1<<' ';
    cout<<endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}