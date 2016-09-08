#include<bits/stdc++.h>
using namespace std;
int Count(int n){
    int endwith0[n],endwith1[n];
    endwith0[0] = 1;
    endwith1[0] = 1;
    for(int i = 1;i<n;i++){
        endwith0[i] = endwith0[i-1] + endwith1[i-1];
        endwith1[i] = endwith0[i-1];
    }
    return endwith0[n-1] + endwith1[n-1];
}
int main(){
    cout<<Count(4);
}
