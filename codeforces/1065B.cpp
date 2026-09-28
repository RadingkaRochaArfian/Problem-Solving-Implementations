#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,m;
    cin>>n>>m;
    ll mn=max(0ll,n-m*2);
    ll cur=1;
    ll edge=m;
    while(edge>0){
        edge-=min(cur,edge);
        cur++;
    }
    ll mx=n;
    if(cur>1)mx=n-cur;
    cout<<mn<<' '<<mx<<endl;
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}