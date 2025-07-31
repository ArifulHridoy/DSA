#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int parent[N];
int size[N];

void make (int x)
    {
        parent[x]=x;
        size[x]=1;
    }

    int find (int x)
    {
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void Union(int x, int y)
    {
        x=find(x);
        y=find(y);

        if(x!=y)
        {
            if(size[x]<size[y])
            swap(x,y);
            parent[y]=x;

            size[x]+=size[y];
        }
    }

int main()

{
    int n,k;
    cin>>n>>k;

    for(int i=1; i<=n; i++)
    make(i);

    while(k--)
    {
        int u,v;
        cin>>u>>v;
        Union(u,v);

        int cc=0;
        for(int i=1; i<=n; i++)
        {
            if(find(i)==i) cc++;
        }
        cout<<"Connected components : "<<cc<<endl;
    }

}
