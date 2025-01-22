#include<iostream>
#include<vector>
using namespace std;

void dfs(const vector<vector<int>>& adjMatrix, int node, vector<bool> &visited)
{
    cout<<node+1<< " ";

    visited[node]=true;

    for(int i=0; i<adjMatrix[node].size(); i++)
        {
        if(adjMatrix[node][i]==1 && !visited[i])
        {
            dfs(adjMatrix,i,visited);
        }
    }
}

int main()
{
    vector<vector<int>> adjMatrix = {
        {0, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0}
};

    int nodes = adjMatrix.size();
    vector<bool> visited(nodes, false);

    cout<<"DFS Traversal: ";
    dfs(adjMatrix, 0, visited);
    cout<<endl;

    return 0;
}
