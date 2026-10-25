#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>a,b;
ll n;
void swap1(){
    for(int i=0;i<2*n-1;i+=2){
        ll hold=a[i];
        a[i]=a[i+1];
        a[i+1]=hold;
    }
}
void swap2(){
    for(int i=0;i<n;i++){
        ll hold=a[i];
        a[i]=a[n+i];
        a[n+i]=hold;
    }
}
bool isSorted(){
    for(int i=0;i<2*n-1;i++){
        if(a[i]>a[i+1]){
            return false;
        }
    }
    return true;
}
ll check(int start){
    a=b;
    for(int i=1;i<=2*n;i++){
        ll swap=(i%2)?start:1-start;
        if(swap==1){
            swap1();
        }else{
            swap2();
        }
        if(isSorted()){
            return i;
        }
    }
    return INT_MAX;
}
void solve() {
    cin>>n;
    a.resize(2*n);
    for(auto &x:a)cin>>x;
    b=a;
    if(isSorted()){
        cout<<0<<endl;
        return;
    }
    ll r1=check(1),r2=check(0);
    ll mn=INT_MAX;
    mn=min(r1,r2);
    cout<<(mn==INT_MAX?-1:mn)<<endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}