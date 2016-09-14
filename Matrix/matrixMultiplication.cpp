#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("inp.txt","r",stdin);
    int a[10][10],b[10][10],result[10][10];
    int rowA = 2,colA = 3,rowB = 3,colB = 2;
    for(int i = 0;i<rowA;i++)
    {///input Matrix A
        for(int j = 0;j<colA;j++){
            cin>>a[i][j];
        }
    }
    for(int i = 0;i<rowB;i++)
    {///input Matrix B
        for(int j = 0;j<colB;j++){
            cin>>b[i][j];
        }
    }
    if(colA!=rowB)
    {/// number of of column of Matrix A must be same to the Number of Row of Matrix B
        cout<<"Matrix Multiplication Impossible";
        return 0;
    }
    for(int i = 0;i<rowA;i++)
    {
        for(int j = 0;j<colB;j++)
        {
            int sum = 0;
            for(int k = 0;k<rowB;k++)
            {
                sum += (a[i][k]*b[k][j]);
            }
            result[i][j] = sum;
        }
    }
    for(int i = 0;i<rowA;i++)
    {/// Number of row of Result Matrix is equal to the number of row of A Matrix
        for(int j = 0;j<colB;j++)
        {/// Number of column of Result Matrix is equal to the number of Column of B Matrix
            cout<<result[i][j]<< " ";
 
        }
        cout<<endl;
    }
}
