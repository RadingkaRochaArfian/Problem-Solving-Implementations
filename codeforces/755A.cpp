#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isPrime(int n){
    if(n==2)return true;
    if(n<=1||n%2==0)return false;
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
void solve() {
    int n;cin>>n;
    for(int m=1;m<=1e3;m++){
        if(!isPrime(n*m+1)){
            cout<<m<<endl;
            return;
        }
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}