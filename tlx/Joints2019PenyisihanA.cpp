#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll x,n,m;
    cin >>x>>n>>m;
    bool sit=false;
    bool happy=false;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int j=0;
        while(j<m){
            if(s[j]!='O'){
                j++;
                continue;
            }
            int start=j;
            while(j<m && s[j]=='O'){
                j++;
            }
            int len=j-start;
            if(len>=x){
                sit=true;
                bool r=j==m||s[j]!='P';
                bool l=start==0 || s[start-1]!='P';
                if(len>=x+2){
                    happy=true;
                }else if(len==x){
                    if(l&&r)happy=true;
                }else if (len==x+1){
                    if(l||r)happy=true;
                }
            }
        }
    }
    if(!sit)cout<<"BALIK AJA";
    else if (!happy)cout<<"TERPAKSA";
    else cout<<"SENANG";
    cout<<endl;
}
int main(){
    int t=1;
    while(t--){
        solve();
    }
}