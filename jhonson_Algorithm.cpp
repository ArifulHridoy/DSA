#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF=1e15;

bool bellman(ll n, vector<tuple<ll,ll,ll>>&edges, vector<ll>&dis)
{
    dis.assign(n,INF);
    dis[0]=0;
    for(ll i=0; i<n-1; i++)
    {
        for(auto[u,v,w]:edges)
        {
            if(dis[u]<INF) dis[v]=min(dis[v],dis[u]+w);
        }
    }
    for(auto[u,v,w]:edges)
    {
        if(dis[u]<INF && dis[u]+w<dis[v]) return false;
    }
    return true;
}

vector<ll>dijkstra(ll s, ll n, vector<vector<pair<ll,ll>>>&adj)
{
    vector<ll>dis(n,INF);
    dis[s]=0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>>pq;
    pq.push({0,s});
    while(!pq.empty())
    {
        auto[d,u]=pq.top(); pq.pop();
        if(d>dis[u]) continue;

        for(auto[v,w]:adj[u])
        {
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
    return dis;
}

void reweight(vector<tuple<ll,ll,ll>>&edges,vector<vector<pair<ll,ll>>>&adj,
              vector<ll>&h, ll n)
{
    adj.assign(n, {});
    for(auto[u,v,w]:edges)
    {
        ll newW=w+h[u]-h[v];
        adj[u].push_back({v,newW});
    }
}

void jhonson(ll n, vector<tuple<ll,ll,ll>>&edges)
{
    vector<tuple<ll,ll,ll>>newEdges=edges; //dummy vertex connected with all n
    for(ll i=0; i<n; i++) newEdges.push_back({n,i,0}); //vertices with 0 cost
    vector<ll>h;
    if(!bellman(n+1,newEdges,h))
    {
        cout<<"Neg cycle"<<endl;
        return;
    }
    //reweighting
    vector<vector<pair<ll,ll>>>adj;
    reweight(edges,adj,h,n);

    vector<vector<ll>>disMat(n,vector<ll>(n,INF));
    for(ll u=0; u<n; u++)
    {
        vector<ll>dis=dijkstra(u,n,adj);
        for(ll v=0; v<n; v++)
        {
            if(dis[v]<INF) disMat[u][v]=dis[v]-h[u]+h[v];
            }
    }
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            if(disMat[i][j]==INF) cout<<"INF ";
            else cout<<disMat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin>>n>>m;
    vector<tuple<ll,ll,ll>>edges;
    for(ll i=0; i<m; i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }
    jhonson(n,edges);
}

