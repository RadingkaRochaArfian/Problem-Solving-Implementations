#include<bits/stdc++.h>
using namespace std;
int n;
void solve(){
    cin>>n;
    vector<int>p(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    vector<int>st;
    for(int i=0;i<n;i++){
        int mx=p[i];
        while(!st.empty()&&st.back()>p[i]){
            mx=max(mx,st.back());
            st.pop_back();
        }
        st.push_back(mx);
    } 
    cout<<st.size()<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}