#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){//268A
    int n;
    cin>>n;
    vector<pair<int,int>>a;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        a.push_back({x,y});
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i].first==a[j].second){
                ans++;
            }
            if(a[i].second==a[j].first){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}