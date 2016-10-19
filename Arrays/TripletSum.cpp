#include<bits/stdc++.h>
using namespace std;
int arr[500];
void Triplet(int n,int make){
    sort(arr,arr+n);
    for(int i = 0;i<n-2;i++){
        int left = i+1,right = n-1;
        while(left<right){
            if(arr[i]+arr[left]+arr[right] == make){
                cout<<arr[i]<<" "<<arr[left]<<" "<<arr[right]<<endl;
                --right;
                ++left;
            }
            else if(arr[i] + arr[left] + arr[right]>make)
                --right;
            else if(arr[i] + arr[left]+arr[right]<make)
                ++left;
        }
    }
}
int main(){
    int n,make;
    cin>>n>>make;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    Triplet(n,make);
}
