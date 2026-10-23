#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,k;
void solve() {
    cin>>n>>m>>k;
    if(m<n-1){
        cout<<"NO"<<endl;
    }else if(m>n*(n-1)/2){
        cout<<"NO"<<endl;
    }else if(n==1 && k<2){
        cout<<"NO"<<endl;
    }else if(n==1&&k>1){
        cout<<"YES"<<endl;
    }else if(m<n*(n-1)/2 && k>3){
        cout<<"YES"<<endl;
    }else if(m==n*(n-1)/2&&k>2){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}