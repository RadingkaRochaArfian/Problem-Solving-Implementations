#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
vector<ll>a;
void solve() {
    cin>>n>>k;
    a.resize(2*n+1);
    for(auto &x:a){
        cin>>x;
    }
    for(int i=1;i<2*n;i++){
        if(i%2==1 &&a[i-1]<a[i]-1&&a[i]-1>a[i+1]){
            a[i]--;
            k--;
        }
        if(k==0)break;
    }
    for(auto x:a){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}