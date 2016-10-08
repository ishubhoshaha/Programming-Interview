/*
* Time Complexity : O(MaximumNumber+N);
* Sort Type: Unstable Sort
*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000
int freequency[MAX];
vector<int> sortedData;
int main(){
    unsigned int n,a,mxNumber=0;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a;
        ++freequency[a];
        mxNumber = max(mxNumber,a);
    }
    for(int i = 0;i<=mxNumber;i++){
        for(int j = 0;j<freequency[i];j++){
            sortedData.push_back(i);
        }
    }
    cout<<"After Sorting: ";
    for(int i = 0;i<sortedData.size();i++){
        cout<<sortedData[i]<<" ";
    }
}
