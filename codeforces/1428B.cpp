#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
string s;
void solve() {
    cin>>n>>s;
    bool cw=false,ccw=false;
    for(int i=0;i<n;i++){
        if(s[i]=='<')cw=true;
        if(s[i]=='>')ccw=true;
    }
    if(cw && ccw){
        ll ans=0;
        s+=s[0];
        for(int i=0;i<n;i++){
            if(s[i]=='-'||s[i+1]=='-')ans++;
        }
        cout<<ans<<endl;
    }else{
        cout<<n<<endl;
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}