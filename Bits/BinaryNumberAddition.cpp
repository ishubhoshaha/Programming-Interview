#include<bits/stdc++.h>
using namespace std;
int main(){
    //Input should be in lsb to msb form

    string a,b,op="";
    cout<<"First Num:\t";
    cin>>a;
    cout<<"Second Num:\t";;
    cin>>b;
    if(a.size()!=b.size()){
        int as = a.size();
        int bs = b.size();
        int l = abs(as - bs);
        //cout<<l<<endl<<endl;
        if(as>bs){
            b.insert(b.begin(),l,'0');
        }
        else{

            a.insert(a.begin(),l,'0');
        }
    }
    //cout<<a<<endl<<b;
    int c = 0;
    for(int i = a.size()-1;i>=0;i--){
        int x,y;
        x = a[i]-'0';
        y = b[i]-'0';
        int s = x^y^c;
        op+=s+'0';
        c = x&c | y&c | x&y ;
    }
    if(c!=0){
        op+=c+'0';
    }
    reverse(op.begin(),op.end());
    cout<<"After Adding: \t"<<op;
}
