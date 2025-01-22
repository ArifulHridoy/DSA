#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(const vector<vector<int>>& adjMatrix, int node1) {
    int nodes=adjMatrix.size();
    vector<bool> visited(nodes,false);
    queue<int>q;

    visited[node1]=true;
    q.push(node1);

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout<<node+1<< " ";

        for (int i=0; i<adjMatrix[node].size(); i++)
            {
            if(adjMatrix[node][i]==1 && !visited[i])
            {
                visited[i]=true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

int main() {
    vector<vector<int>> adjMatrix = {
        {0, 1, 1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0},
        {1, 0, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0}
    };

    bfs(adjMatrix, 0);

    return 0;
}
