#include<bits/stdc++.h>
using namespace std;
int Partion(int arr[],int start,int end){
    int pivotValue = arr[end],j = start;
    for(int i = start;i<=end;i++){
        if(arr[i]<pivotValue){
            swap(arr[i],arr[j++]);
        }
    }
    swap(arr[j],arr[end]);
    return j;
}
int* QuickSort(int arr[],int start,int end){
    if(start<end){
        int partionIndex = Partion(arr,start,end);
        QuickSort(arr,start,end-1);
        QuickSort(arr,partionIndex+1,end);
    }
    return arr;
}
int main(){
    int arr[] = {3,2,9,11,5,12,0};//= {3,-2,5,-1,1};
    int size = sizeof arr / sizeof(int);
    int *p = QuickSort(arr,0,size-1);
    cout<<"After Sorting: ";
    for(int i = 0;i<size;i++){
        cout<<p[i]<<" " ;
    }
}
