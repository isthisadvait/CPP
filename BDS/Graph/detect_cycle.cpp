#include <bits/stdc++.h>
using namespace std;
// Detect Cycle in undirected graph
bool detectCycle(int v, vector<int> adj[])
{
    vector<int> vis(v, false);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            if (dfs(i, adj, vis, -1))
                return true;
    }
    return false;
}
void dfs(int s, vector<int> adj[], vector<int> &vis, int parent)
{
    vis[s] = true;
    for (int u : adj[s])
    {
        if (!vis[u])
        {
            if (dfs(u, adj, vis, s) == true)
                return true;
        }
        else if (u != parent)
            return true;
    }
    return false;
}

int main() {}