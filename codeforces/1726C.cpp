#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
void solve() {
    cin>>n;
    string s;cin>>s;
    n<<=1;
    ll cnt=0;
    for(int i=1;i<n;i++){
        if(s[i]=='('&& s[i-1]=='('){
            cnt++;
        }
    }
    cout<<1+cnt<<endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}