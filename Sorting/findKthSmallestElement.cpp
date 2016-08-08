/*
* http://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
* O(n+klogk)
*/
#include<bits/stdc++.h>
using namespace std;
int Partion(int arr[],int start,int end){
    int pivot = arr[end],j = start;
    for(int i = start;i<=end;i++){
        if(arr[i]<pivot){
            swap(arr[i],arr[j++]);
        }
    }
    swap(arr[end],arr[j]);
    return j;
}
int KthElement(int arr[],int start,int end,int k){
    k--;
    while(1){
        int partionIndex = Partion(arr,start,end);
        if(partionIndex==k){
            return partionIndex;
        }
        else if(partionIndex<k){
            start = partionIndex + 1;
        }
        else if(partionIndex>k){
            end = partionIndex - 1;
        }
    }

}
int main(){
    int arr[] = {3,2,9,11,5,12,0};
    int size = sizeof arr / sizeof(int);
    cout<<arr[KthElement(arr,0,size-1,4)];
}
