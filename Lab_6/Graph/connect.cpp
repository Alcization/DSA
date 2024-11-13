#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <list>
using namespace std;

void dfs(int node, vector<int> graph[], vector<bool>& visited){
    if (visited[node]) return;
    visited[node] = true;
    for (int i = 0; i < (int) graph[node].size(); i++) dfs(graph[node][i], graph, visited); 
}
int countComponents(int n, vector<vector<int>>& edges) {
    vector <bool> visited(n);
    if (!n) return 0;
    vector <int> graph[n];
    for (int i = 0; i < (int) edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
        dfs(i, graph, visited);
        ret++;
        }
    }
    return ret;
}

int connectedComponents(vector<vector<int>>& edges) 
{
    int n = edges.size();
    vector<vector<int>> graph;
    for(int i = 0; i < n; i++)
    {
        if (!edges[i].empty())
        {
            for (int j = 0; j < (int) edges[i].size(); j++)
            {
                if (edges[i][j] > i) graph.push_back({i, edges[i][j]});
            }
        }
    }
    return countComponents(n, graph);
}

int main()
{
    vector<vector<int>> graph {
        {1},
        {0, 2},
        {1, 3},
        {2},
        {}
    };
    cout << connectedComponents(graph);
    return 0;
}