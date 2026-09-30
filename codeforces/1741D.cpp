#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>a;
int dc(int l,int r){
    if(r-l==1)return 0;
    int mid=(l+r)>>1;
    int ml=*max_element(a.begin()+l,a.begin()+mid);
    int mr=*max_element(a.begin()+mid,a.begin()+r);
    int ans=0;
    if(ml>mr){
        ans++;
        for(int i=0;i<(mid-l);i++){
            swap(a[i+l],a[mid+i]);
        }
    }
    return dc(l,mid)+dc(mid,r)+ans;
}
void solve(){
    a.clear();
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    int ans=dc(0,m);
    if(is_sorted(a.begin(),a.end())){
        cout<<ans<<endl;
    }else{
        cout<<-1<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}