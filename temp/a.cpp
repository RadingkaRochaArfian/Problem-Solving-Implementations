#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
void solve() {
    cin>>n;
    for(ll k=n/2;k>=1;k--){
        if(gcd(n,k)==1){
            cout<<k<<endl;
            return;
        }
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}