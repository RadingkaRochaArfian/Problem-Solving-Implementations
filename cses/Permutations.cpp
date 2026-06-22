#include<iostream>
using namespace std;
int main(){
    long n;cin>>n;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }else if(n==2 || n==3){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    for(long i=2;i<=n;i+=2){
        cout<<i<<" ";
    }
    for(long i=1;i<=n;i+=2){
        cout<<i<<" ";
    }
    cout<<endl;
}
