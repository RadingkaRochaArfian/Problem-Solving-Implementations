#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<ll>g;
void solve() {
    cin>>n;
    g.assign(n+1,0);
    for(int i=1;i<=n;i++)cin>>g[i];
    for(int i=1;i<=n;i++){
        if(g[g[g[i]]]==i){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}