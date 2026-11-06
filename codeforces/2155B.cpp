#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;
void solve() {
    cin>>n>>k;
    if(k==n*n-1){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(k>0){
                cout<<"U";
                k--;
            }else if(i<n-1){
                cout<<"D";
            }else if(j<n-1){
                cout<<"R";
            }else{
                cout<<"L";
            }
        }
        cout<<endl;
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}