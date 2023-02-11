#include <bits/stdc++.h>
using namespace std;

struct sgmntree
{
    vector<int> sgt;
    int n;
    void init(int n)
    {
        this->n = n;
        sgt.resize(4 * n, 0);
    }

    void buildTree(int st, int en, int node, vector<int> &v)
    {
        if (st == en)
        {
            sgt[node] = v[st];
        }
        int mid = st + (en - st) / 2;
        // left subtree [st,mid]
        buildTree(st, mid, 2 * node + 1, v);
        // right subtree [mid+1,en]
        buildTree(mid + 1, en, 2 * node + 2, v);
        sgt[node] = sgt[node * 2 + 1] + sgt[node * 2 + 2];
    }
    int queryOnTree(int st, int en, int l, int r, int node)
    {
        // non - overlapping
        if (st > r || en < l)
            return 0;
        // complete overlap
        if (st >= l && en <= r)
            return sgt[node];
        // partial overlap
        int mid = st + (en - st) / 2;
        int q1 = queryOnTree(st, mid, l, r, 2 * node + 1);
        int q2 = queryOnTree(mid + 1, en, l, r, 2 * node + 2);
        return q1 + q2;
    }
    void updateOnTree(int st, int en, int node, int idx, int val)
    {
        // base case
        if (st == en)
        {
            sgt[node] = val;
            return;
        }
        int mid = st + (en - st) / 2;
        if (idx <= mid)
        {
            // left subtree
            updateOnTree(st, mid, 2 * node + 1, idx, val);
        }
        else
        {
            // right subtree
            updateOnTree(mid + 1, en, 2 * node + 2, idx, val);
        }
        sgt[node] = sgt[2 * node + 1] + sgt[2 * node + 2];
    }

    void build(vector<int> &v)
    {
        buildTree(0, n - 1, 0, v);
    }
    int query(int l, int r)
    {
        return queryOnTree(0, n - 1, l, r, 0);
    }
    void update(int x, int y)
    {
        updateOnTree(0, n - 1, 0, x, y);
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sgmntree t;

    t.init(n);
    t.build(v);

    return 0;
}