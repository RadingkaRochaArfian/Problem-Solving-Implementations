#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
int dr[4]={1,-1,0,0};
int dc[4]={0,0,-1,1};
vector<string> s;
vector<vector<ll>> g;
vector<ll>h;
ll area(){
    vector<ll>new_h=h;
    new_h.push_back(0);
    stack<ll>st;
    ll res=0;
    for(ll i=0;i<m+1;i++){
        while(!st.empty()&&new_h[st.top()]>new_h[i]){
            ll hi=new_h[st.top()];st.pop();
            ll w=st.empty()?i:i-st.top()-1;
            res=max(res,hi*w);
        }
        st.push(i);
    }
    return res;
}
void solve() {
    cin>>n>>m;
    s.resize(n);
    g.assign(n,vector<ll>(m,0));
    for(ll i=0;i<n;i++){
        cin>>s[i];
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(s[i][j]!='O')continue;
            bool ok=true;
            for(ll k=0;k<4;k++){
                ll nr=i+dr[k];
                ll nc=j+dc[k];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&s[nr][nc]=='P'){
                    ok=false;
                    break;
                }
            }
            if(ok)g[i][j]=1;
        }
    }
    ll ans=0;
    h.assign(m,0);
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            h[j]=g[i][j]?h[j]+1:0;
        }
        ans=max(ans,area());
    }
    cout<<ans<<endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}