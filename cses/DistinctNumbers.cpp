#include<iostream>
using namespace std;
void merge(long arr[], int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int l1[n1],l2[n2];
    for(int i=0;i<n1;i++){
        l1[i]=arr[left+i];
    }
    for(int i=0;i<n2;i++){
        l2[i]=arr[mid+i+1];
    }
    int i=0,j=i,k=left;
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
void merge_sort(long arr[],int left,int right){
    if(left>=right)return;
    int mid=left+(right-left)/2;
    merge_sort(arr,left,mid);
    merge_sort(arr,mid+1,right);
    merge(arr,left,mid,right);
}
int main(){
    int n;
    cin>>n;
    long arr[n];
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        arr[i]=m;
    }
    merge_sort(arr,0,n);
    long sum=1;
    int el=0;
    for(int i=0;i<n;i++){
        if(i!=0&&el!=arr[i]){
            sum++;
        }
        el=arr[i];
    }
    cout<<sum<<endl;
    return 0;
}