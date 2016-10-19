/*
* Time Complexity : O(nlogn)
*/
#include<bits/stdc++.h>
using namespace std;
int arr[500];
int main(){
    int n,make;
    cin>>n>>make;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int left = 0,right = n-1;
    while(left<right){
        if(arr[left]+arr[right]==make)
        {
            cout<<arr[left]<<" "<<arr[right]<<endl;
            --right;
            ++left;

        }
        else if(arr[left]+arr[right]>make){
            --right;
        }
        else if(arr[left]+arr[right]<make){
            ++left;
        }
    }
    return 0;
}
