/*
* Time Complexity : O(node+edge)
* Reference : http://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>graph[101];
int indegree[101];
void TopSort(int node){
    int t = 0;
    queue<int>q;
    for(int i = 1;i<=node;i++){ ///Assume node start from 1
        if(indegree[i]==0)
            q.push(i);

    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ++t;
        for(int i = 0;i<graph[u].size();i++){
            int v = graph[u][i];
            indegree[v]--;
            if(indegree[v]==0)
                q.push(v);

        }
        cout<<u<<" ";
    }
    if(t!=node) cout<<"Not possible to sort this graph toplogically";
    cout<<endl;
}
int main(){
    freopen("in.txt","r",stdin);
    int node,edge;
    cin>>node>>edge;
    for(int i = 0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        indegree[v]++;
    }
    TopSort(node);
    /*Cycle Detection*/
//    for(int i = 1;i<node;i++){
//        if(indegree[i]!=0){
//            cout<<"Cycle Exist";
//            break;
//        }
//    }
}
