#include<bits/stdc++.h>
using namespace std;
void solve(){
        int n;
        char c;
        string s;
    int cnt=0;
    cin>>n>>c>>s;
    for(int i=0;i<n/2;i++){
        if(s[i]==s[n-i-1])continue;
        if(s[i]!=c)cnt++;
        if(s[n-1-i]!=c)cnt++;
    }
    cout<<cnt<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}