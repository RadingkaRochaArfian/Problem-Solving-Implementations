#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,ax,ay,bx,by,cx,cy;
void solve() {
    cin>>n>>ax>>ay>>bx>>by>>cx>>cy;
    if((bx<ax)==(cx<ax)&&(by<ay)==(cy<ay)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}