#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n;
    cin>>n;
    vector<string>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    bool valid=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]=='1'){
                if((i+1==n || a[i+1][j]=='1'||j+1==n||a[i][j+1]=='1')){
                    continue;
                }else{
                    valid=false;
                    break;
                }    
            }
        }
    }
    if(valid){
        cout<<"YES";
    }else{
        cout<<"NO";
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