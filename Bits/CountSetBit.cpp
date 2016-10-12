
#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int main(){

    int n;
    cin>>n;
    int ans = 0;
    for(int i = 0;i<=20;i++){ //Maximum n is 9999999 cause loop iterates 21 times
        if(((1<<i) & n)!=0)
            ans++;
    }
    cout<<ans<<endl;
}

