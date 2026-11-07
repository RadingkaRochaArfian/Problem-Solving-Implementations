#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,r1,r2,c1,c2;
ll block(ll x,ll y){
    if((x==1||x==n)&&(y==1||y==m)){
        return 2;
    }else if(x==1||x==n||y==1||y==m){
        return 3;
    }
    return 4;
}
void solve() {
    cin>>n>>m>>r1>>c1>>r2>>c2;
    cout<<min(block(r1,c1),block(r2,c2))<<endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}