#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b,c;
void solve() {
    cin>>a>>b>>c;
    if((a+b+c)%2==1){
        cout<<"Impossible"<<endl;
        return;
    }
    ll x=(a+b-c)/2;
    ll y=(b+c-a)/2;
    ll z=(c+a-b)/2;
    if(x<0||y<0||z<0){
        cout<<"Impossible"<<endl;
    }else{
        cout<<x<<' '<<y<<' '<<z<<endl;
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}