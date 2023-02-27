#include <bits/stdc++.h>

using namespace std;

// summation
struct fenwick
{
    int n;
    vector<int> fn;

    void init(int _n)
    {
        this->n = _n;
        fn.resize(n + 1, 0);
        }
    void add(int x, int y)
    {
        x++;
        while (x <= n)
        {
            fn[n] += y;
            x += (x & (-x));
        }
    }
    int sum(int x)
    {
        int ans = 0;
        while (x)
        {
            ans += fn[x];
            x -= (x & (-x));
        }
        return ans;
    }
    int sum(int l, int r)
    {
        l++;
        r++;
        return sum(r) - sum(l - 1);
    }
};

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    // cout << v.size();

    fenwick tree;

    tree.init(v.size());

    // ree.build(v);

    // cout << tree.query(0, 4) << '\n';

    // tree.update(0, 1, 10);

    // cout
    //   << tree.query(0, 4) << '\n';

    return 0;
}