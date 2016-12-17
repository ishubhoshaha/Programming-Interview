#include<bits/stdc++.h>
using namespace std;
vector<int> Merged(int arr1[],int arr2[],int n,int m){
    int i = 0,j = 0;
    vector<int>list;
    while(i<n and j<m){
        if(arr1[i]<=arr2[j]){
            list.push_back(arr1[i]);
            i++;
        }else{
            list.push_back(arr2[j]);
            j++;
        }
    }
    if(i<n){
        for(int l = i;l<n;l++){
            list.push_back(arr1[l]);
        }
    }else if(j<m){
        for(int l = j;l<m;l++){
            list.push_back(arr2[l]);
        }
    }
    return list;
}
int main(){
    int arr1[] = {4,45,89,90,123};
    int arr2[] = {7,28,43,101,145,160};
    int n = sizeof(arr1)/sizeof(int);
    int m = sizeof(arr2)/sizeof(int);
    vector<int>list = Merged(arr1,arr2,n,m);
    cout<<"Merged and Sorted Array: ";
    for(int i = 0;i<list.size();i++){
        cout<<list[i]<<" ";
    }
}
