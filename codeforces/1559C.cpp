#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<ll>a;
void solve() {
    cin>>n;
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(a[1]){
        cout<<n+1<<' ';
        for(int i=1;i<=n;i++){
            cout<<i<<' ';
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<n;i++){
        if(!a[i]&&a[i+1]){
            for(int j=1;j<=i;j++){
                cout<<j<<' ';
            }
            cout<<n+1<<' ';
            for(int j=i+1;j<=n;j++){
                cout<<j<<' ';
            }
            cout<<endl;
            return;
        }
    }
    for(int i=1;i<=n+1;i++){
        cout<<i<<' ';
    }
    cout<<endl;
}
int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}