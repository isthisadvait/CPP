#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dir1 = {

    {-1, 0}, {0, 1}, {1, 0}, {0, -1}

};
vector<vector<int>> dir2 = {

    {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}

};
bool isValid(int i, int j, vector<vector<bool>> &vis, int rmax, int cmax)
{
    if (i < 0 || i >= rmax || j < 0 || j >= cmax || vis[i][j])
        return false;
    return true;
}

vector<int> bfsOnMatrix(vector<vector<int>> &mat)
{
    int rmax = mat.size();
    int cmax = mat[0].size();
    vector<vector<bool>> vis(5, vector<bool>(5, false));
    queue<pair<int, int>> qu;
    qu.push({0, 0});
    vis[0][0] = true;
    vector<int> ans;
    while (!qu.empty())
    {
        auto p = qu.front();
        qu.pop();
        int x = p.first, y = p.second;
        ans.push_back(mat[x][y]);
        for (int i = 0; i < dir1.size(); i++)
        {
            int newx = x + dir1[i][0], newy = y + dir1[i][1];
            if (isValid(newx, newy, vis, rmax, cmax))
            {
                qu.push({newx, newy});
                vis[newx][newy] = true;
            }
        }
    }

    return ans;
}
int main()
{
    vector<vector<int>> mat = {
        {2, 3, 4, 5},
        {31, 61, 52, 40},
        {56, 71, 51, 41}};
    vector<int> ans = bfsOnMatrix(mat);
    for (auto x : ans)
    {
        cout << x << " ";
    }
}