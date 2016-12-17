#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100];
int parent[100];
int dist[100];
bool visit[100];
int bfs(int sx,int target){
    queue<int> q;
    q.push(sx);
    parent[sx] = 0;
    dist[sx] = 0;
    visit[sx] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
//        if(u==target)
//            do something
        for(int i = 0;i<graph[u].size();i++){
            int v = graph[u][i];
            if(!visit[v]){
                q.push(v);
                visit[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u;
            }
         }
    }
}
int main(){
    int node,edge,src,target;
    cin>>node>>edge;
    for(int i = 0;i<edge;i++){
        int from,to;
        cin>>from>>to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    cout<<"Source and Target Node: ";
    cin>>src>>target;
    bfs(src,target);
//    for(int i = 0;i<node;i++){
//        cout<<parent[i]<<" ";
//    }
//    cout<<endl;
    cout<<"Shortest Distance from "<<src<<" to "<<target<<" is "<<dist[5];
}
