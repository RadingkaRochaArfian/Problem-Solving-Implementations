#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
void solve() {
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        return;
    }else if(n==2){
        cout<<-1<<endl;
        return;
    }
    vector<vector<int>>a(n,vector<int>(n));
    a[0][0]=1;a[n-1][n-1]=n*n;
    ll x=n*n-1;
    for(int i=1;i<n-1;i++){
        for(int j=i;j>=0;j--,x--){
            a[i-j][j]=x;
        }
    }
    x=2;
    for(int i=n-2;i>0;i--){
        for(int j=0;j+i<n;j++,x++){
            a[n-j-1][i+j]=x;
        }
    }
    for(int i=0;i<n;i++,x++){
        a[n-i-1][i]=x;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
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