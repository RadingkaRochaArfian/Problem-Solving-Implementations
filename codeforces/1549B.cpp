#include<bits/stdc++.h>
using namespace std;
string sa;
string sb;
int n;
void solve(){
    cin>>n>>sa>>sb;
    int ans=0;
    for(int i=0;i<n;i++){
        if(sb[i]=='0')continue;
        if(sa[i]=='0'){
            ans++;
            sa[i]='2';
        }else if(i>0&&sa[i-1]=='1'){
            ans++;
            sa[i-1]='2';
        }else if(i+1<n&&sa[i+1]=='1'){
            ans++;
            sa[i+1]='2';
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}
