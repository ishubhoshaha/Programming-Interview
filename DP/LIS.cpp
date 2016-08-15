#include<bits/stdc++.h>
using namespace std;
#define N 1000
int arr[] = {2,-1,4,3,5,-1,3,2};
int dir[N];
vector<int>lis;
int LIS(int n){
    for(int i = 0;i<n;i++){
        int x = lower_bound(lis.begin(),lis.end(),arr[i])-lis.begin();
        if(x==lis.size()){
            lis.push_back(arr[i]);
            dir[i] = lis.size();
        }
        else{
            lis[x] = arr[i];
            dir[i] = x+1;
        }
    }
    cout<<"LIS SIZE :"<<lis.size()<<endl;

}
void printSequence(int n){
    vector<int> ans;
    int x,s=-1;
    for(int i = 0;i<n;i++){
        if(dir[i]>s){
            x = i;
            s = dir[i];
        }
    }
    ans.push_back(arr[x]);
    for(int i = x -1;i>=0;i--){
        if(arr[i]<arr[x] and dir[i]==s-1){
            ans.push_back(arr[i]);
            x = i;
            s = dir[i];
        }
    }
    cout<<"Sequence is: ";
    for(int i = ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
}
int main(){
    int n = sizeof arr/sizeof(int);
    LIS(n);
    printSequence(n);
}
