#include <iostream>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

class graph{
    int a[100][100],n,s;
public:
    void getdata();
    void bfs();
    void dfs();
};

void graph::getdata()
{
    cout<<"Enter number of nodes in the graph :"<<endl;
    cin>>n;
    cout<<"Enter adjacency matrix : "<<endl;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
          cin>>a[i][j];
    cout<<"Node to traverse from : "<<endl;
    cin>>s;
}

void graph::bfs()
{
    int* visited=new int[n];
    int queue[10], front=-1, i, rear=0;

    for(int j=0; j<n; j++)
        visited[j]=0;

    queue[rear]=s;
    visited[s]=1;

    while(front!=rear)
    {
        cout<<queue[++front]<<" ";
        i=queue[front];

        for(int j=0; j<n; j++)
        {
            if(a[i][j]!=0 && visited[j]!=1)
            {
                queue[++rear]=j;
                visited[j]=1;
            }
        }
    }
}

void graph::dfs()
{
   int* visited=new int[n];
    int stack[10], top=-1, i;

    for(int j=0; j<n; j++)
        visited[j]=0;

        i=stack[++top]=s;
        visited[s]=1;

        while(top>=0)
        {
           i=stack[top];
           cout<<stack[--top]<<" ";

           for(int j=n-1; j>=0; j--)
           {
               if(a[i][j]!=0 && visited[j]!=1)
               {
                   stack[++top]=j;
                   visited[j]=1;
               }
           }

        }
}


int main()
{
    graph g;
    g.getdata();
    g.bfs();
    g.getdata();
    g.dfs();
    return 0;
}
