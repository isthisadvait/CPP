#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, vector<int> a, vector<vector<int>> queries)
{
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int q;
    cin >> q;
    vector<vector<int>> qr(q, vector<int>(2));
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        qr[i][0] = x;
        qr[i][1] = y;
    }
}