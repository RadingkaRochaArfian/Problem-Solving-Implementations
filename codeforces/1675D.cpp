#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n;cin>>n;
    vector<bool>leaf(n+1,true);
    vector<int>p(n+1);
    for(int i=1;i<=n;i++){
        cin>>p[i];
        leaf[p[i]]=false;
    }
    if(n==1){
        cout<<"1\n1\n1\n";
        return;
    }
    vector<bool>vis(n+1);
    vector<int>path[n+1];
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!leaf[i])continue;
        vis[i]=true;
        int v=i;
        path[i].push_back(v);
        while(!vis[p[v]]){
            v=p[v];
            vis[v]=true;
            path[i].push_back(v);
        }
        cnt++;
    }
    cout<<cnt<<endl;
    for(auto x:path){
        if(x.empty())continue;
        cout<<x.size()<<endl;
        reverse(x.begin(),x.end());
        for(auto y:x){
            cout<<y<<' ';            
        }
        cout<<endl;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}