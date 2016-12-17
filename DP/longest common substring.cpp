#include<bits/stdc++.h>
using namespace std;
int LCSubstring(string stra,string strb){
    int dp[100][100],result = -1;
    for(int i = 0;i<=stra.size();i++){
        for(int j = 0 ;j<=strb.size();j++){
            if(i==0 or j==0){
                dp[i][j] = 0;
            }
            else if(stra[i-1]==strb[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                result = max(dp[i][j],result);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    cout<<result;
}
int main(){
    string stra,strb;
    cin>>stra>>strb;
    LCSubstring(stra,strb);
}
