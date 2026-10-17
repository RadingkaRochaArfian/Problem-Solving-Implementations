
#include <bits/stdc++.h>
using namespace std;
int main() {

    int n,m;
    cin>>n>>m;
    vector<bool>vis(n+1,false);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        vis[u]=true;
        vis[v]=true;
    }
    int center=-1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            center=i;
            break;
        }
    }
    cout<<n-1<<endl;
    for(int i=1;i<=n;i++){
        if(i!=center){
            cout<<center<<" "<<i<<endl;
        }
    }
}