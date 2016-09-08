#include<bits/stdc++.h>
using namespace std;
void Reverse(unsigned int *num){
    unsigned int rev = 0;
    int sz = sizeof (num)*8 - 1;
    for(int i = 0;i<=sz;i++){
        rev = rev | (*num & 1);
        rev = rev << 1;
        *num = *num >> 1;
        //cout<<rev<<" "<<*num<<endl;
    }
    *num = rev;
}
int main(){
    unsigned int number = 11;
    cout<<"Before Reverse: "<<number<<endl;
    Reverse(&number);
    cout<<"After Reverse: "<<number<<endl;
}
