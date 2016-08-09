#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[] = {5,2,5,1,4};
    for(int i = 0;i<5-1;i++){ //UP TO N-1
        for(int j = 0;j<5-i-1;j++){ //UP TO N-i-1
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i = 0;i<5;i++)
        cout<<a[i]<<" ";
}
