#include<bits/stdc++.h>
using namespace std;
int* InsertionSort(int arr[],int n){
    for(int i = 1;i<n;i++){
        if(arr[i-1]>arr[i]){
            for(int j = 0;j<i;j++){
                if(arr[j]>arr[i]){
                    swap(arr[j],arr[i]);
                }
            }
        }
    }
    return arr;
}
int main(){
    int arr[] = {3,-2,5,-1};
    int size = sizeof arr / sizeof(int);
    int *p = InsertionSort(arr,size);
    cout<<"After Sorting: ";
    for(int i = 0;i<size;i++){
        cout<<p[i]<<" " ;
    }

}
