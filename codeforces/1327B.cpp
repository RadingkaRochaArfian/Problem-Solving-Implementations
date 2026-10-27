#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;
vector<bool>a;
void solve() {
    cin>>n;
    a.assign(n+1,false);
    ll not_vis=-1;
    for(ll i=1;i<=n;i++){
        cin>>k;
        bool vis=false;
        for(ll j=1;j<=k;j++){
            ll x;cin>>x;
            if(!vis&&!a[x]){
                a[x]=true;
                vis=true;
            }
        } 
        if(!vis){
            not_vis=i;
        }
    }
    if(not_vis==-1){
        cout<<"OPTIMAL"<<endl;
    }else{
        ll u=-1;
        for(ll i=1;i<=n;i++){
            if(!a[i]){
                u=i;
                break;
            }
        }
        cout<<"IMPROVE"<<endl<<not_vis<<" "<<u<<endl;
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}