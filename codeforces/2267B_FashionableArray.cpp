#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    map<int,int,greater<>>mp;

    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
    }
    bool cek=false;
    int i=0;
    while(!cek){
        cek=true;
        for(auto [k,v] :mp){
            if(v==0)continue;
            cout<<k<<' ';
            mp[k]--;
            cek=false;
        }
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}