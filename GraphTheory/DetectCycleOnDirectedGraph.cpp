#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GREY 1
#define BLACK 2
vector<int>adjList[100],v;
int color[100];
int parent[100];
void PrintCycle(int node,int u){
    if(node == u){
        for(int i = v.size()-1;i>=0;i--){
            cout<<v[i]<<" ";
        }
        cout<<u;
        return;
    }
    v.push_back(node);
    PrintCycle(parent[node],u);
}
int dfs(int node){
    color[node] = GREY;
    for(int i = 0;i<adjList[node].size();i++){
        int u = adjList[node][i];
        if(color[u]==GREY){
            //cout<<
            cout<<"Found Cycle"<<endl;
            cout<<u<<" ";
            PrintCycle(node,u);
        }
        if(color[u]==WHITE){
            color[u]= GREY;
            parent[u] = node;
            dfs(u);
        }
    }
    color[node] = BLACK;
}
int main(){
    freopen("in.txt","r",stdin);
    int node,edge;
    cin>>node>>edge;
    for(int i = 0;i<edge;i++){
        int from,to;
        cin>>from>>to;
        adjList[from].push_back(to);
    }
    dfs(1);
//    for(int i = 1;i<=node;i++){
//        for(int j = 0;j<adjList[i].size();j++){
//            cout<<adjList[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}
