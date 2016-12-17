#include<bits/stdc++.h>
using namespace std;
int main(){
 
    int a,b;
    cin>>a>>b;
    while(b){
        int carry = a&b;
        a = a^b;
        b = carry<<1;
    }
    cout<<a;
}
