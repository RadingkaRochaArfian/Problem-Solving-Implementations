#include<iostream>
using namespace std;
int main(){
    long long n;cin>>n;
    long long sum=0;
    long long cur;cin>>cur;
    for(long i=1;i<n;i++){
        long m;cin>>m;
        if(m<cur){
            sum+=(cur-m);
        }
        if(cur<m){
            cur=m;
        }
    }
    cout<<sum<<endl;
}