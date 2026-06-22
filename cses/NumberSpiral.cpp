#include<iostream>
using namespace std;
long long checkValue(long long x,long long y){
    if(x%2==0&&y%2==0&&x<y){
        return (y-1)*(y-1)+x;
    }else if(x%2==0&&y%2==0&&x>y){
        return x*x-(y-1);
    }else if(x%2==0&&y%2==0&&x==y){
        return x*x-(x-1);
    }else if(x%2==1&&y%2==1&&x<y){
        return y*y-(x-1);
    }else if(x%2==1&&y%2==1&&x>y){
        return (x-1)*(x-1)+y;
    }else if(x%2==1&&y%2==1&&x==y){
        return x*x-(x-1);
    }else if(x%2==0&&y%2==1&&x<y){
        return y*y-(x-1);
    }else if(x%2==1&&y%2==0&&x<y){
        return y*y-(y-1)-(y-x);
    }else if(x%2==1&&y%2==0&&x>y){
        return (x-1)*(x-1)+y;
    }else if(x%2==0&&y%2==1&&x>y){
        return x*x-(y-1);
    }else{
        return -1;
    }
}
int main(){
    long long n;cin>>n;
    for(long long i=0;i<n;i++){
        long long x,y;
        cin>>x;cin>>y;
        cout<<checkValue(x,y)<<endl;
    }
}