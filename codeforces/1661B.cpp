#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=32768;
ll dfs(ll v){
    ll ans=INT_MAX;
    for(ll i=0;i<=15;i++){
        for(ll j=0;j<=15;j++){
            if(((v+i)<<j)%mod==0){
                ans=min(ans,i+j);
            }
        }
    }
    return ans;
}
void solve(){
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        cout<<dfs(v)<<' ';
    }        
}
int main(){
    int t;
    t=1;
    while(t--){
        solve();
    }
}