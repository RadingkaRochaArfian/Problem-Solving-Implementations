#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n;
    cin>>n;
    ll sum=n*(n+1)/2;
    cout<<sum%2<<endl;
    ll half=sum/2;
    vector<int>a;
    for(int i=n;i>=1;i--){
        if(half>=i){
            a.push_back(i);
            half-=i;
        }
    }
    cout<<a.size()<<' ';
    for(int x:a){
        cout<<x<<' ';
    }
    cout<<endl;
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}