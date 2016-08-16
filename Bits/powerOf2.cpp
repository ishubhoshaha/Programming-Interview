#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 128;
    bool check = n & (n-1); // if n is power of 2 then check is 0
    if(!check)
        cout<<"Power of 2";
    else 
	cout<<"Not Power of 2";
}
