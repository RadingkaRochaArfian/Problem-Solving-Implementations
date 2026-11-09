#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll r,c;
vector<string>g;
void solve() {
    cin>>r>>c;
    g.clear();
    for(ll i=0;i<r;i++){
        string s;cin>>s;
        g.push_back(s);
    }
    for(ll i=0;i<r;i++){
        for(ll j=0;j<c;j++){
            bool fail=false;
            if(g[i][j]=='S'){
                if(i>0&&g[i-1][j]=='W'){
                    fail=true;
                }
                if(i<r-1&&g[i+1][j]=='W'){
                    fail=true;
                }
                if(j>0&&g[i][j-1]=='W'){
                    fail=true;
                }
                if(j<c-1&&g[i][j+1]=='W'){
                    fail=true;
                }
            }
            if(fail){
                cout<<"NO"<<endl;
                return;
            }
            if(g[i][j]=='.'){
                g[i][j]='D';
            }
        }
    }
    cout<<"YES"<<endl;
    for(ll i=0;i<r;i++){
        cout<<g[i]<<endl;
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}