/*
Time Complexity: O(n^2)
Space Complexity O(n^2)
*/
#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int LPI(string str){
    int sz = str.size();
    for(int i = 0;i<sz;i++){
        dp[i][i] = 1;
    }
    for(int len = 2;len<=sz;len++){
        for(int i = 0;i<sz-len+1;i++){
            int j = i + len -1;
            if(len == 2 and str[i]==str[j]){
                dp[i][j] = 2;
            }
            else if(str[i]==str[j]){
                dp[i][j] = 2 + dp[i+1][j-1];
            }
            else if(str[i]!=str[j]){
                dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
            }
        }
    }
    return dp[0][sz-1];
}

int main(){
    string str;
    cin>>str;

    cout<<LPI(str)<<endl;
    for(int i = 0;i<str.size();i++){
        for(int j = 0;j<str.size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
