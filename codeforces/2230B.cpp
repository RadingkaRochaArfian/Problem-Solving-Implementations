#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    string s;cin>>s;
    ll ans=0,l=0,r=0;
    for(auto x : s){
        if(x=='1'||x=='3'){
            r++;
        }
    }
    ans=r;
    for(auto x:s){
        if(x=='2'){
            l++;
        }
        if(x=='1'||x=='3'){
            r--;
        }
        ans=max(ans,l+r);
    }
    cout<<s.length()-ans<<endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}