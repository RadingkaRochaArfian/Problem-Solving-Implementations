#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
void solve() {
    cin>>n>>m;
    ll ans=1;
    ll pow=n;
    ll num=3;
    while(pow){
        if(pow%2==1)ans=(ans*num)%m;
        num=(num*num)%m;
        pow>>=1;
    } 
    cout<<(ans-1+m)%m<<endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}