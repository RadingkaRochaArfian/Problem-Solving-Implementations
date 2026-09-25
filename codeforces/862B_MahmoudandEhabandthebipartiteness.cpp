#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<int> v[100005];
ll side[2];
void dfs(int node,int parent,int color){
    side[color]++;
    for(int i=0;i<v[node].size();i++){
        if(v[node][i]!=parent){
            dfs(v[node][i],node,color^1);
        }
    }
}
void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1,0,0);
    cout<<side[0]*side[1]-(n-1)<<endl;
}
int main(){
    solve();
}