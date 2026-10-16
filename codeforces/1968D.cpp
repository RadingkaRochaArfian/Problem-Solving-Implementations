#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k,pb,ps;
vector<ll>p,a,vis;
ll scoring(ll start){
    vis.assign(n+1,false);
    ll move=0,mx=0,s=start,kt=k;
    while(!vis[s]&&kt>0){
        vis[s]=1;
        mx=max(mx,move+kt*a[s]);
        move+=a[s];
        kt--;
        s=p[s];
    }
    return mx;
}
void solve() {
    cin>>n>>k>>pb>>ps;
    a.assign(n+1,0);
    p.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll b=scoring(pb);
    ll s=scoring(ps);
    cout<<(b<s?"Sasha":b>s?"Bodya":"Draw")<<endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}