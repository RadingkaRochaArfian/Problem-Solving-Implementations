#include<iostream>
using namespace std;
void merge(long arr[],long left,long mid,long right){
    long n1=mid-left+1;
    long n2=right-mid;
    long l1[n1],l2[n2];
    for(long i=0;i<n1;i++){
        l1[i]=arr[left+i];
    }
    for(long i=0;i<n2;i++){
        l2[i]=arr[mid+1+i];
    }
    long i=0,j=i,k=left;
    while(i<n1&&j<n2){
        if(l1[i]<l2[j]){
            arr[k]=l1[i];
            i++;
        }else{
            arr[k]=l2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=l1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=l2[j];
        j++;
        k++;
    }
}
void merge_sort(long arr[], long left,long right){
    if(left>=right)return;
    long mid=left+(right-left)/2;
    merge_sort(arr,left,mid);
    merge_sort(arr,mid+1,right);
    merge(arr,left,mid,right);
}
int main(){
    long n; cin>>n;long arr[n-1];
    for(long i=0;i<n-1;i++){
        long m;cin>>m;
        arr[i]=m;
    }
    merge_sort(arr,0,n-2);
    if(arr[0]!=1){
        cout<<1;
        return 0;
    }
    long m=arr[0];
    for(long i=1;i<n-1;i++){
        if(arr[i]!=m+1){
            long f=arr[i]-1;
            cout<<f;
            return 0;
        } 
        m++;
    }
    cout<<n;
}