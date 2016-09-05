/* Binary Search */
#include<bits/stdc++.h>
using namespace std;
vector<int> arr={30,45,78,2,11,-12,45,45,99,15555};
int BinarySearch(int item,int len){
    --len;
    int start = 0,mid;
    while(start<=len){
        mid = (start+len)/2;
        if(item==arr[mid]){
            return mid;/// Item found and return index
        }
        arr[mid]<item ? start = mid + 1 : len = mid-1;
    }
    return -1;/// Item Not found
}
int main(){
    sort(arr.begin(),arr.end());
 
//    for(int i = 0;i<arr.size();i++){
//        cout<<arr[i]<<endl;
//    }
    int index = BinarySearch(78,arr.size());
    index!=-1 ? cout<<"Item found at "<<index + 1<<endl : cout<<"Item does not found."<<endl;
}
