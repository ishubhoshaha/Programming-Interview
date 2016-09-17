#include<bits/stdc++.h>
using namespace std;
string converTo,convertFrom;
int dp[501][501];
int EditDistance(){
    for(int i = 0;i<500;i++){
        dp[0][i] = i;
        dp[i][0] = i;
    }
    for(int i = 1;i<=converTo.size();i++){
        for(int j = 1;j<=convertFrom.size();j++){
            if(converTo[i-1]==convertFrom[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1+ min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
        }
    }
    return dp[converTo.size()][convertFrom.size()];
}
void print(){
    int i = converTo.length() ;
    int j = convertFrom.length() ;
    while(1){
        if(i==0 or j==0)
            break;
        if(converTo[i-1]==convertFrom[j-1]){
            i--;
            j--;
        }else if(dp[i][j]==dp[i-1][j-1]+1){
            i--;
            j--;
            cout<<"From String 1 " <<convertFrom[j]<<" Converted To "<<converTo[i]<<endl;
        }else if(dp[i][j]==dp[i-1][j]+1){
            i--;
            cout<<"Delete from String 2 "<<converTo[i]<<endl;
        }
        else if(dp[i][j]==dp[i][j-1]+1){
            j--;
            cout<<"Delete from 1 "<<convertFrom[j]<<endl;
        }
 
    }
}
int main(){
    cout<<"Convert from: ";
    cin>>convertFrom;
    cout<<endl<<"Convert To: ";
    cin>>converTo;
    cout<<"Minimum Edit Distance: "<<EditDistance()<<endl;
    print();
}
