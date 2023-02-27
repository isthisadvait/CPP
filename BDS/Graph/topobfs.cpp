#include <bits/stdc++.h>
using namespace std;

// kahn's bfs based algorithm
vector<int> topoSort(int v, vector<int> adj[])
{
    // code here
    vector<int> ind(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (int x : adj[i])
        {
            ind[x]++;
        }
    }
    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < v; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        ans.push_back(f);

        for (int v : adj[f])
        {
            ind[v]--;
            if (ind[v] == 0)
                q.push(v);
        }
    }
    return ans;
}
void dfs(int v, vector<int> &adj[], vector<bool> &vis, stack<int> &st)
{
    vis[v] = true;
    for (int x : adj[v])
    {
        if (!vis[x])
        {
            dfs(x, adj, vis, st);
        }
    }
    st.push(v);
}
// DFS based topoSort
vector<int> topo(int v, vector<int> adj[])
{

    stack<int> st;
    vector<int> ans;

    vector<bool> vis(v, false);
    for (int u : adj[v])
    {
        if (!vis[u])
        {
            dfs(u, adj, vis, st);
        }
    }
    while (!st.empty())
    {
        int x = st.top();
        ans.push_back(x);
        st.pop();
    }
}
int main() {}