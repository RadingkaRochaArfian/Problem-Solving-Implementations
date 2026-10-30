#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;
void solve() {
    cin>>n>>k;
    if(k>=n-1){
        cout<<1<<endl;
    }else{
        cout<<n<<endl;
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}