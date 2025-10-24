#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;

bool bellmanFord(int n, int start, const vector<tuple<int,int,int>> &edges, vector<int> &dis)
{
    dis.assign(n, INF);
    dis[start]=0;

    for(int i=0; i<n-1; i++)
    {
        for(auto &[u,v,w]:edges)
        {
            if(dis[u]!=INF && dis[u]+w < dis[v])
            {
                dis[v]=dis[u]+w;
            }
        }
    }
    for(auto &[u,v,w]:edges)
        {
            if(dis[u]!=INF && dis[u]+w < dis[v])
            {
                return false;
            }
        }
        return true;
}


int main()
{
    int n,m;
    cin>>n>>m;

    vector<tuple<int,int,int>>edges;

    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        edges.push_back(make_tuple(u,v,w));
    }

    int start; cin>>start;
    vector<int>dis;

    if(bellmanFord(n, start, edges, dis))
    {
        for(int i=0; i<n; i++)
        {
            if(dis[i]==INF) cout<<i<<" : INF"<<endl;
            else cout<<i<<" : "<<dis[i]<<endl;
        }
    }

    else cout<<"Neg edge cycle found."<<endl;
}
