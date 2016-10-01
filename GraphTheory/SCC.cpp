/*
* Time Complexity : O(V+E) + O(V+E)
* Reference: Data Structure Book by Mahabubul Alam
* http://www.geeksforgeeks.org/strongly-connected-components/
*/

#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100],revGraph[100],lst,component[100];
int isVisit[100];
void DFS(int node){
    isVisit[node] = 1;
    for(int i = 0;i<graph[node].size();i++){
        int v = graph[node][i];
        if(!isVisit[v]){
            DFS(v);
        }
    }
    lst.push_back(node);
}
void DFS2(int node,int n){
    isVisit[node] = 1;
    component[n].push_back(node);
    for(int i = 0;i<revGraph[node].size();i++){
        int v = revGraph[node][i];
        if(!isVisit[v]){
            DFS2(v,n);
        }
    }
}
int main(){
    freopen("in.txt","r",stdin);
    int node,edge;
    cin>>node>>edge;
    for(int i = 0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        revGraph[v].push_back(u);
    }
    int comp = 0;
    DFS(0);
    memset(isVisit,0,sizeof isVisit);
    reverse(lst.begin(),lst.end());
    for(int i = 0;i<lst.size();i++){
        if(!isVisit[lst[i]]){
            DFS2(lst[i],comp);
            comp++;
        }
    }
    //cout<<comp;
    for(int i = 0;i<comp;i++){
        cout<<"Component #"<<i+1<<">";
        for(int j=0;j<component[i].size();j++){
            cout<<component[i][j]<<" ";
        }
        cout<<endl;
    }
}
