/*
*Find empty cell
*  If there are no empty cells, return true, problem solved.
*  For every empty cell try digit from 1 to 9
*    a) If the cell is safe for digit at grid[row][col]
*        grid[row][col]=number and recursively try and fill in rest of the grid
*    b) If recursion successful, return true
*    c) Else, undo the selection, cell[row][col]=0 and try another
*  If all numbers are tried and solution not found, return false
*/

#include<bits/stdc++.h>
using namespace std;
bool isempty(int grid[][9],int row,int col){
    if (grid[row][col]==0){
        return true;
    }
    else
        return false;
}
pair<int,int> EmptyCell(int grid[][9]){
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(isempty(grid,i,j)){
                return make_pair(i,j);
            }
        }
    }
    return make_pair(-1,-1);
}
bool isUsedinRow(int grid[][9],int row,int item){
    for(int i = 0;i<9;i++){
        if(grid[row][i]==item)
            return true;
    }
    return false;
}
bool isUsedinColumn(int grid[][9],int col,int item){
    for(int i = 0;i<9;i++){
        if(grid[i][col]==item)
            return true;
    }
    return false;
}
bool isUsedinGrid(int grid[][9],int row, int col,int item){ ///tricky of this problem is to select this start row and col
    for(int i = row;i<row+3;i++){
        for(int j = col;j<col+3;j++)
            if(grid[i][j]==item)
                return true;
    }
    return false;
}
bool solve(int grid[][9]){
    pair<int,int>emptycell = EmptyCell(grid);
    int r = emptycell.first,c = emptycell.second;
    if(r==-1) return true;
    for(int i = 1;i<=9;i++){
        int item = i;
//        if(r==0 and c = 8)

        if(!isUsedinColumn(grid,c,item) and !isUsedinRow(grid,r,item) and !isUsedinGrid(grid,r-r%3,c-c%3,item)){
        //cout<<r<<" "<<c<<" "<<item<<endl;
            grid[r][c] = item;
            if(solve(grid))
                return true;
            grid[r][c] = 0;
        }
    }
    return false;
}
int main(){
    int grid[][9] = {
                    { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
                    { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
                    { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
                    { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
                    { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
                    { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
                    { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
                    { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
                    { 0, 0, 0, 0, 8, 0, 0, 7, 9 } };

    if(solve(grid)){
        cout<<"bingo! got solution"<<endl;
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"No solution found";
    }
}

