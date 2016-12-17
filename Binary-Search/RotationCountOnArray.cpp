/*
*Time Complexity O(logN)
*/
#include<bits/stdc++.h>
using namespace std;
int BinarySearch(int arr[],int n,int start,int end){
    int mid,next,prev;
    while(start<=end){
        mid = (start + end)/2;
        if(arr[start]<=arr[end])
            return start;
        next = (mid + 1)%n; /// Modulation operation for edge case
        prev = (mid + n - 1)%n;
        if(arr[mid]<arr[next] and arr[mid]<arr[prev])
            return mid;
        if(arr[mid]<arr[end])
            end = mid -1;
        else if(arr[mid]>arr[start])
            start = mid +1 ;
    }
}
int main(){
    int arr[] = {6,7,1,2,3,4,5};
    int n = sizeof arr/sizeof (int);
    cout<<"This array Roated to Right "<<BinarySearch(arr,n,0,n-1)<<" time(s).";
}
