#include<iostream>
using namespace std;
int main(){
    string input;cin>>input;
    long n=input.length();
    long max=1;
    long init=1;
    for(long i=0;i<n;i++){
        if(i>0){
            if(input[i]!=input[i-1]){
                init=1;
            }else{
                init++;
            }
        }
        if(max<init){
            max=init;
        }
    }
    cout<<max<<endl;
}