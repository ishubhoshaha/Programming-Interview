/*
* time complexity O(n^2)
* space complexity O(n)
*/
#include<bits/stdc++.h>
using namespace std;
int col[100];
bool isSafe(int row,int column){
    for(int i = 0;i<row;i++){
        if(col[i]==column or abs(col[i]-column)==abs(i-row)){
            return false;
        }
    }
    return true;
}
void NQueen(int row, int n){
    static int set = 0;
    for(int i = 0;i<n;i++){
        if(isSafe(row,i)){
            col[row] = i;
            if(row==n-1){
                cout<<"Set "<<++set<<": "<<endl<<"[row,column]"<<endl;
                for(int j = 0;j<n;j++){
                    cout<<"["<<j<<","<<col[j]<<"]"<<endl;
                }
            }else NQueen(row+1,n);
        }
    }
}
int main(){
    NQueen(0,4);
}
