#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
vector<ll>a;
void solve() {
    cin>>n>>m;
    a.assign(n+1,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n>m||n==2){
        cout<<-1<<endl;
        return;
    }
    ll sum=2*accumulate(a.begin(),a.end(),0);
    cout<<sum<<endl;
    for(int i=1;i<=n-1;i++){
        cout<<i<<' '<<i+1<<endl;
    }
    cout<<n<<' '<<1<<endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}