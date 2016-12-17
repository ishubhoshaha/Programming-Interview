#include<bits/stdc++.h>
#define LOWERBOUND true
#define UPPERBOUND false
using namespace std;
vector<int> v ={1,3,100,5,7,7,-1,7,17,8,9,0,9,12,18,18};
int BinarySearch(int item,int len,bool isLower){
    --len;
    int start = 0,mid,index = -1;
    while(start<=len){
        mid = (start+len)/2;
        if(item==v[mid]){
            index = mid;
            isLower ? len = mid - 1 : start = mid + 1;
        }
        else if(item<v[mid]){
            len = mid-1;
        }
        else if(item>v[mid]){
            start = mid+1;
        }
    }
    return index;
}
int main(){
    sort(v.begin(),v.end());
    cout<<"7 exist in V array ";
    cout<<BinarySearch(7,v.size(),UPPERBOUND)-BinarySearch(7,v.size(),LOWERBOUND) + 1 <<" time(s)"<<endl;
}
