#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
void solve() {
    cin>>n;
    vector<int>a(n+1);
    vector<int>b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    vector<int>tag(n+1,1),ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(a[j]<=a[i]&&b[i]<=b[j])tag[i]=0;
        }
        if(tag[i]==1)ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(auto x:ans)cout<<x<<' ';
    cout<<endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}