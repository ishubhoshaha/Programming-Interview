#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int main(){
    int n,a[MAX],total = 0;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a[i];
        total+=a[i];
    }
    bool okgotit = false;
    int leftSum = 0;
    for(int i = 0;i<n;i++){
        total-=a[i];
        if(total==leftSum){
            okgotit = true;
            cout<<i+1<<" ";
        }
        leftSum+=a[i];
    }
    if(!okgotit)
        cout<<-1<<endl;
}
