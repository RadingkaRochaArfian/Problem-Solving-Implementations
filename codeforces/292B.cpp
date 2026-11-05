#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>deg,freq;
ll n,m;
void solve() {
    cin>>n>>m;
    deg.assign(n+1,0);
    for(ll i=0;i<m;i++){
        ll a,b;cin>>a>>b;
        deg[a]++;
        deg[b]++;
    }
    freq.assign(n+1,0);
    for(ll i=1;i<=n;i++){
        freq[deg[i]]++;
    }
    if(freq[2]==n){
        cout<<"ring topology"<<endl;
    }else if(freq[n-1]==1&&freq[1]==n-1){
        cout<<"star topology"<<endl;
    }else if(freq[1]==2&&freq[2]==n-2){
        cout<<"bus topology"<<endl;
    }else{
        cout<<"unknown topology"<<endl;
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
