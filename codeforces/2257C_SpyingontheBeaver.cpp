#include<bits/stdc++.h>
using namespace std;
int n,m;
void solve(){
    cin>>n;
    vector<int> depth(n,0);
    vector<int> p(n,-1);
    for(int v=1;v<n;v++){
        cin>>p[v];
        p[v]--;
        depth[v]=depth[p[v]]+1;
    }
    cin>>m;
    vector<int> pt(m);
    bool root=false;
    for(int i=0;i<m;i++){
        cin>>pt[i];
        pt[i]--;
        if(!pt[i]){
            root=true;
        }
    }
    cout<<m-1<<' ';
    int skip;
    if(root){
        skip=0;
    }else{
        int mnDepth=1e9;
        int closest=1;
        for(int v:pt){
            if(mnDepth>depth[v]){
                mnDepth=depth[v];
                closest=v;
            }
        }
        skip=closest;
    }
    for(int v:pt){
        if(v!=skip){
            cout<<v+1<<' ';
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}