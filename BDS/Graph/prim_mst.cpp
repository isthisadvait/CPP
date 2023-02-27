#include <bits/stdc++.h>
using namespace std;

class Graph
{
    // Adjacency List
    int v;
    vector<pair<int, int>> *l;

public:
    Graph(int v)
    {
        this->v = v;
        this->l = new vector<pair<int, int>>[v];
    }
    void addEdge(int x, int y, int w)
    {
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }
    int prim_mst()
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> vis(n, false);
        int ans = 0;
        // begin

        pq.push({0, 0}); // weight ,node
        while (!pq.empty())
        {
            auto best = pq.top();
            pq.pop();
            int toEdge = best.second;
            int weight = best.first;
            if (vis[toEdge])
            {
                // discard and continue
                continue;
            }
            // otherwise take the current edge and push it's connected nodes to pq
            ans += weight;
            vis[toEdge] = true;
            for (auto x : l[toEdge])
            {
                if (!vis[x.first])
                {
                    pq.push({x.second, x.first});
                }
            }
        }
        return ans;
    }
}

int
main()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g.addEdge(x - 1, y - 1, w);
    }
    cout << g.prim_mst() << endl;
}