#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
void solve() {
    cin>>n;
    vector<int>p(n+1);
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    set<int>st;
    for(int i=1;i<=n;i++){
        int d;
        cin>>d;
        while(st.find(d)==st.end()){
            st.insert(d);
            d=p[d];
        }
        cout<<st.size()<<" ";
    }
    cout<<endl;
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}