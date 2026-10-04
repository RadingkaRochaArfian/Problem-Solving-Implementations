#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
int res;
vector<vector<int>>g;
int dfs(int x){
    int bal=s[x-1]=='B'?-1:1;
    if(g[x].empty())return bal;
    stack<int>st;
    st.push(x);
    while(!st.empty()){
        int xtop=st.top();
        st.pop();
        for(int child:g[xtop]){
            bal+=dfs(child);
        }
    }
    if(bal==0)res++;
    return bal;
}
void solve() {
    cin>>n;
    g=vector<vector<int>>(n+1);
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        g[x].push_back(i);
    }
    cin>>s;
    res=0;
    dfs(1);
    cout<<res<<endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}