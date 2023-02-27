#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int v;
    list<int> *l;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
        {
            l[j].push_back(i);
        }
    }
    void printAdjList()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << "-->";
            for (auto node : l[i])
            {
                cout << node << ",";
            }
            cout << "\n";
        }
    }
    void bfs(int source)
    {
        queue<int> q;
        vector<bool> vis(v, false);
        q.push(source);
        vis[source] = true;
        // cout << q.size() << " here";
        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            cout << f << endl;
            for (auto nb : l[f])
            {
                if (!vis[nb])
                {
                    vis[nb] = true;
                    q.push(nb);
                }
            }
        }
    }
    void shortest(int source)
    {
        queue<int> q;
        vector<bool> vis(v, false);
        vector<int> dis(v, 0);
        vector<int> par(v, -1);
        q.push(source);
        vis[source] = true;
        par[source] = source;
        dis[source] = 0;
        while (!q.empty())
        {
            int f = q.front();
            q.pop();
            // cout << f << endl;
            for (auto nb : l[f])
            {
                if (!vis[nb])
                {
                    vis[nb] = true;
                    dis[nb] = dis[f] + 1;
                    par[nb] = f;
                    q.push(nb);
                }
            }
        }
        for (auto x : dis)
            cout << x << " ";
        cout << endl;
        for (auto x : par)
            cout << x << " ";
        cout << endl;
    }
    void dfsHelper(int source, vector<bool> &vis)
    {
        vis[source] = true;
        cout << source << " \n";
        for (auto nb : l[source])
        {
            if (!vis[nb])
            {
                dfsHelper(nb, vis);
                // cout << nb << " \n";
            }
        }
    }
    void dfs(int source)
    {
        vector<bool> vis(v, false);
        dfsHelper(source, vis);
    }
    // cycle detection in undirected graph as single component
    bool dfsCycle(int node, vector<bool> &vis, int parent)
    {
        vis[node] = true;
        for (auto nbr : l[node])
        {
            if (!vis[nbr])
            {
                return dfsCycle(nbr, vis, node);
            }
            else if (nbr != parent)
            {
                return true;
            }
        }
        return false;
    }
    bool contains_cycle()
    {
        vector<bool> vis(v, false);
        return dfsCycle(0, vis, -1);
    }
};
int main()
{
    Graph g(3);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    // g.addEdge(1, 2);
    // g.addEdge(2, 3);
    // g.addEdge(3, 4);
    // g.addEdge(3, 5);
    // g.addEdge(5, 4);
    // g.printAdjList();
    // g.shortest(0);
    // g.bfs(1);
    cout << g.contains_cycle();
}