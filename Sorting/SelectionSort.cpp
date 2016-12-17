#include<bits/stdc++.h>
using namespace std;
int* SelectionSort(int arr[],int n){

    for(int i = 0;i<n-1;i++){
        int minimum = i;
        for(int j = i + 1;j<n;j++){
            if(arr[j]<arr[minimum]){
                minimum = j;
            }
        }
        swap(arr[minimum],arr[i]);
    }
    return arr;
}
int main(){
    int arr[] = {3,-2,5,-1};
    int size = sizeof arr / sizeof(int);
    int *p = SelectionSort(arr,size);
    cout<<"After Sorting: ";
    for(int i = 0;i<size;i++){
        cout<<p[i]<<" " ;
    }
}
