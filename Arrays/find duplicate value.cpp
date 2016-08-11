/* source: geeksforgeeks
O(N) */
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[100] = {7,2,3,1,3,6,6,7,1,2};
    for(int i = 0;i<10;i++){
        int x = abs(arr[i]);
        if(arr[x]>=0){
            arr[x] *= -1;
        }
        else{
            cout<<abs(arr[i])<<" ";
        }
    }
}
