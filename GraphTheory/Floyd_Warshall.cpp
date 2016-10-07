/*
* Time Comlexity : O(n^3)

* Reference:
Data Structure book by Mahabubul Hasan
www.shafaetsplanet.com/planetcoding/index8e9f.html?p=1927

* Sample input
4 6
4 3 8
4 1 20
3 2 5
2 1 2
1 3 3
2 3 2
*/

#include<bits/stdc++.h>
using namespace std;
int weight[100][100];
int node,edge;
void FloyedWarshall(){
    for(int k = 1;k<=node;k++){ ///Node starts from 1
        for(int i = 1;i<=node;i++){
            for(int j = 1;j<=node;j++){
                if(weight[i][j]>weight[i][k]+weight[k][j]){
                    weight[i][j] = weight[i][k]+weight[k][j];
                }
            }
        }
    }
}
void init(){
    for(int i = 0;i<100;i++){
        for(int j = 0;j<100;j++){
            weight[i][j] = 1<<29;
        }
        weight[i][i] = 0;
    }
}
int main(){
    init();
    cin>>node>>edge;
    for(int i = 0;i<edge;i++){
        int u,v,c;
        cin>>u>>v>>c;
        weight[u][v] = c; ///if 2 node holds more than 1 edge then we store only 1 edge that has minimum weight
    }
    FloyedWarshall();
    cout<<weight[4][2]<<" ";

}

