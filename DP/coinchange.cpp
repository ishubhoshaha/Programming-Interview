#include<bits/stdc++.h>
using namespace std;
#define MAXCoin 100
#define MAXAmount 100
int dp[MAXCoin][MAXAmount],coin[MAXCoin],c,make;
int CC(int i,int amount){
    if(i>=c){
        if(amount==0)
            return 1;
        else return 0;
    }
    if(dp[i][amount]!=-1)
        return dp[i][amount];
    int x = 0,y = 0;
    if(amount-coin[i]>=0){
        x = CC(i,amount-coin[i]);
    }
    y = CC(i+1,amount);
    dp[i][amount] = x + y;
    return dp[i][amount];

}
int main(){
    memset(dp,-1,sizeof dp);
    cin>>make>>c;
    for(int i = 0;i<c;i++){
        cin>>coin[i];
    }
    cout<<CC(0,make);
}
