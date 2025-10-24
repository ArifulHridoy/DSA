#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;

void dijkstra(int start, const vector<vector<pair<int,int>>> &adj, vector<int> &dis)
{
    int n=adj.size();
    dis.assign(n, INF);

    dis[start]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater <>> pq;
    pq.push({0,start});

    while(!pq.empty())
    {
        int currDis=pq.top().first;
        int u=pq.top().second;
        pq.pop();

        if(currDis>dis[u]) continue;

        for(auto &[v, weight] : adj[u])
        {
            if(dis[u]+weight < dis[v])
            {
                dis[v]=dis[u]+weight;
                pq.push({dis[v],v});
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n);

    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int start; cin>>start;
    vector<int>dis;

    dijkstra(start,adj,dis);

    for(int i=0; i<n; i++)
    {
        if(dis[i]==INF) cout<<i<<" : INF"<<endl;
        else cout<<i<<" : "<<dis[i]<<endl;
    }

}
