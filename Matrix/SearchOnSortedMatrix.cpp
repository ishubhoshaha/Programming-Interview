#include<bits/stdc++.h>
using namespace std;
bool Search(int arr[4][4],int value){
    int row = 0, col = 3;
    while(1){
        //cout<<arr[row][col]<<" ";
        if(row>3 or col<0)
            return false;
        if(value == arr[row][col]){
            cout<<"Exist at : ["<<row+1<<"]["<<col+1<<"]"<<endl;
            return true;
        }
        if(value > arr[row][col]){
            row++;
        }else {
            col--;
        }
    }
}
int main(){
    int matrix[4][4] = { {10, 20, 30, 40},
                        {15, 25, 35, 45},
                        {27, 29, 37, 48},
                        {32, 33, 39, 50},
                    };
 
    if(!Search(matrix,3)){
        cout<<"Don't Exist";
    }
}
