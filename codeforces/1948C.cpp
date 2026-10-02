#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
void solve(){
    cin>>n;
    vector<string> a(2);
    cin>>a[0]>>a[1];
    int d[][4]={
        {0,0,1,-1},
        {1,-1,0,0}
    };
    vector<vector<bool>> vis(2,vector<bool>(n,false));
    stack<pair<int,int>>st;
    st.push({0,0});
    vis[0][0]=true;
    while(!st.empty()){
        auto [r,c]=st.top();
        st.pop();
        if(r==1&&c==n-1)break;
        for(int i=0;i<4;i++){
            int nr=r+d[0][i];
            int nc=c+d[1][i];
            if(nr<0||nr>=2||nc<0||nc>=n)continue;
            if(a[nr][nc]=='>'){
                nc++;
            }else{
                nc--;
            }
            if(!vis[nr][nc]){
                vis[nr][nc]=true;
                st.push({nr,nc});
            }
        }
    }
    if(vis[1][n-1]){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}