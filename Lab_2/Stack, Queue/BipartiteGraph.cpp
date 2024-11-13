bool isBipartite(vector<vector<int>>& graph) 
{
    int n = graph.size();
    vector<int> color(n, 0); 
    for (int i = 0; i < n; ++i) 
    {
        if (color[i] == 0) 
        {
            queue<int> q;
            q.push(i);
            color[i] = 1; 
            while (!q.empty()) 
            {
                int node = q.front();
                q.pop();
                for (int neighbor : graph[node]) 
                {
                    if (color[neighbor] == 0) 
                    {
                        color[neighbor] = -color[node];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) return false; 
                }
            }
        }
    }
    return true;
}