#include <bits/stdc++.h>
using namespace std;
int n;
void solve(){
    cin>>n;
    priority_queue<int>a;
    long long ans=0;
    while(n--){
        int x;
        cin>>x;
        if(x!=0){
            a.push(x);
        }else{
            if(!a.empty()){
                ans+=a.top();
                a.pop();
            }
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