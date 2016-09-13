#include<bits/stdc++.h>
#define pii pair<int,int>
#define msi map<string,int>
 
#define vpii vector<pii>
#define vmsi vector<msi>
 
 
#define _visit true
#define _unvisit false
#define pb(n) push_back(n)
#define INF 2000000000
 
using namespace std;
vector<pii > graph[100];
vector<int> dist(100, INF);
struct pr{
    int d,src;
};
void dijsktra(int s,int d){
    priority_queue < pii, vector< pii >, greater<pii > > pq;
    dist[s] = 0;
    pq.push(pii(0, s));
    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop();
        int d = top.first, u = top.second;
        if (d == dist[u]){
 
            for(int i=0;i<graph[u].size();i++){
                int v = graph[u][i].first,weight_u_v = graph[u][i].second;
                if (dist[u] + weight_u_v < dist[v]) {
                    dist[v] = dist[u] + weight_u_v;
                    pq.push(pii(dist[v], v));
                }
            }
        }
    }
}
int main(){
    int n,m;
    freopen("r.txt","r",stdin);
    cin>>n>>m;
    cin.ignore();
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
    }
//    cout<<"Adj List:\n";
//    for(int i=1;i<=n;i++){
//        cout<<i<<":";
//        for(int j=0;j<graph[i].size();j++){
//            cout<<graph[i][j].first<<" ";
//        }
//        cout<<endl;
//    }
    int source,dest;
    cin>>source>>dest;
    dijsktra(source,dest);
    cout<<dist[dest];
}
