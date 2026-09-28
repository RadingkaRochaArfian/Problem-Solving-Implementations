#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4*1e5+1;
vector<int>adj[maxn];
bool gone[maxn];
ll mod =1e9+7;
void dfs(int p){
    stack<int>s;
    s.push(p);
    gone[p]=true;
    while(!s.empty()){
        int y=s.top();
        s.pop();
        for(auto x:adj[y]){
            if(!gone[x]){
                gone[x]=true;
                s.push(x);
            }           
        }
    }
}
void solve(){
    int n;
    cin>>n;
    int a[n+1];
    int b[n+1];
    for(int i=1;i<=n;i++)cin>>a[i],adj[i]=vector<int>();
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        gone[i]=false;
        adj[a[i]].push_back(b[i]);       
        adj[b[i]].push_back(a[i]);
    }
    ll ans=1;
    for(int i=1;i<=n;i++){
        if(!gone[i]){
            ans=ans*2%mod;
            dfs(i);
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}