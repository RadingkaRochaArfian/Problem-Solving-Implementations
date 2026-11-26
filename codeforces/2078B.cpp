#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;
void solve() {
    cin>>n>>k;
    if(k%2==1){
        for(int i=0;i<n-1;i++){
            cout<<n<<" ";
        }
        cout<<n-1<<endl;
    }else{
        for(int i=0;i<n-2;i++){
            cout<<n-1<<" ";
        }
        cout<<n<<" "<<n-1<<endl;

    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}