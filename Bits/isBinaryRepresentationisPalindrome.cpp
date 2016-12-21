#include<bits/stdc++.h>
using namespace std;
bool BitStatus(unsigned long long x,unsigned long long k){
    return x&(1<<(k-1));
}
int main(){
    unsigned long long int x;
    cin>>x;
    int numberofbits;
    for(int i = 0;i<64;i++){
        if ((1<<i)>x){
            numberofbits = i;
            break;
        }
    }
    for(int i = 1;i<=numberofbits/2;i++){
        if(BitStatus(x,i)!=BitStatus(x,numberofbits-i+1)){
            cout<<"Binary Representation of "<<x<<" Not Palindrome";
            return 0;
        }
    }
    cout<<"Binary Representation of "<<x<<" is Palindrome";

}
