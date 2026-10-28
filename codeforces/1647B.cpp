#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
const ll MAX_SIZE=1e2;
int a[MAX_SIZE][MAX_SIZE];
void solve() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        for(int j=0;j<m;j++){
            a[i][j]=s[j]-'0';
        }
    }
    for(ll i=0;i<n-1;i++){
        for(ll j=0;j<m-1;j++){
            ll sum=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
            if(sum==3){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}