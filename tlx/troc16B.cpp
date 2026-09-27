#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n,m;
    cin>>n>>m;
    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    ll ans=a[n-1]-a[0];
    for(int i=1;i<n;i++){
        ans=min(ans,(a[i-1]+m)-a[i]);
    }
    cout<<ans<<endl;
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}