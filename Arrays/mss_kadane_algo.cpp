/* [Reference] MyCodeSchool.com
    Heuristic: at least one array element is positive */
#include<bits/stdc++.h>
using namespace std;
int MaxSubArray(int arr[],int size){
    int ans = 0,sum = 0;
    for(int i = 0;i<size;i++){
        if(sum+arr[i]>0)
            sum+=arr[i];
        else sum = 0;
        ans = max(ans,sum);
    }
    return ans;
}
int main(){
    int arr[] = {3,-2,5,-1};
    int size = sizeof arr / sizeof(int);
    cout<<MaxSubArray(arr,size);
}
