#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin>>n;
    vector<int>p(n+1,0);
    for(int i=2;i<=n;i++){
        cin>>p[i];
    }
    vector<int>path;
    int cur = n;
    while (true) {
        path.push_back(cur);
        if (cur == 1) break;
        cur = p[cur];
    }
    reverse(path.begin(), path.end());
        for (int i = 0; i < (int)path.size(); i++) {
        if (i > 0) cout << ' ';
        cout << path[i];
    }
    cout<<endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}