/*
>> http://www.geeksforgeeks.org/divide-and-conquer-maximum-sum-subarray/ | Mycodeschool
>> Time Complexity : O(nlogn)
*/

#include<bits/stdc++.h>
using namespace std;
int MSS(int arr[],int len){
    if(len == 1) return arr[0];
    int mid = len/2;
    int leftMSS = MSS(arr,mid);
    int rightMSS = MSS(arr+mid,len-mid);
    int leftsum,rightsum,sum = 0;
    leftsum = rightsum = (1<<30)*-1;
    for(int i = mid-1;i>=0;i--){
        sum+=arr[i];
        leftsum= max(leftsum,sum);
    }
    sum = 0;
    for(int i = mid;i<len;i++){
        sum+=arr[i];
        rightsum= max(rightsum,sum);
    }
    return max(max(leftMSS,rightMSS),leftsum+rightsum);
}
int main(){
    int arr[100];
    int n;
    cin>>n; // insert number of value;
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<MSS(arr,n);
}
