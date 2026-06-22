#include<iostream>
using namespace std;
long findPermutation(long x){
    if(x==1){
        return 0;
    }else if(x==2){
        x*=x;
        return x*(x-1)/2;
    }else{
        long forbid=4*(x-1)*(x-2);
        x*=x;
        long total=x*(x-1)/2;
        return total-forbid;
    }
}
int main(){
    long n;cin>>n;
    for(int i=1;i<=n;i++){
        cout<<findPermutation(i)<<endl;
    }
}