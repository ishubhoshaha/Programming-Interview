#include<bits/stdc++.h>
using namespace std;
int arr[40][40];
void SpiralOrder(int row,int col){
    int top = 0,left=0,right = col-1,bottom = row-1;
    int dir = 0;
    while(top<=bottom and left<=right){
        if(dir==0){
            for(int i = left;i<=right;i++){
                cout<<arr[top][i]<<" ";
            }
            top++;
            dir = 1;
        }
        else if(dir==1){
            for(int i = top;i<=bottom;i++){
                cout<<arr[i][right]<<" ";
            }
            right--;
 
            dir = 2;
        }
        else if(dir==2){
            for(int i = right;i>=left;i--){
                cout<<arr[bottom][i]<<" ";
            }
            bottom--;
            dir = 3;
        }
        else if(dir==3){
 
            for(int i = bottom;i>=top;i--){
                cout<<arr[i][left]<<" ";
            }
            left++;
            dir = 0;
        }
 
    }
}
int main(){
    //freopen("f.txt","r",stdin);
    int m = 4,n = 4;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Given Matrix: "<<endl;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    SpiralOrder(4,4);
}
