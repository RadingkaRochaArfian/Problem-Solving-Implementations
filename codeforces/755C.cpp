#include <bits/stdc++.h>
using namespace std;

int n;
void solve() {
    cin>>n;
    set<int>st;
    int extra=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        st.insert(x);
        if(x==i)extra++;
    }
    cout<<(st.size()+extra)/2<<endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}