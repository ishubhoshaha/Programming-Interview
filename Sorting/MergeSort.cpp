#include<bits/stdc++.h>
using namespace std;
int arr[100];
int temp[100];
void Merged(int left,int mid,int right){
    int i(left),j(mid+1),k(left);
    while(i<=mid and j<=right){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i++];
        }else if(arr[i]>arr[j]){
            temp[k++] = arr[j++];
        }
    }
    while(i<=mid){
        temp[k++] = arr[i++];
    }
    while(j<=right){
        temp[k++] = arr[j++];
    }
    for(int l = left;l<=right;l++){
        arr[l] = temp[l];
    }
}
void MergeSort(int left,int right){
 
    if(left<right){
        int mid = (left+right)/2;
        MergeSort(0,mid);
        MergeSort(mid+1,right);
        Merged(left,mid,right);
    }
}
int main(){
    int n;
    cout<<"Number Data (MAX-100): ";
    cin>>n;
    cout<<"Insert Data: ";
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    MergeSort(0,n-1);
    cout<<endl<<"After sorting: ";
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
 
}
