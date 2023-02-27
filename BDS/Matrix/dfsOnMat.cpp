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
void dfs(vector<vector<int>> &mat, int i, int j, int rmax, int cmax, vector<vector<bool>> &vis, vector<int> &ans)
{
    if (i < 0 || j < 0 || i >= rmax || j >= cmax || vis[i][j])
        return;
    ans.push_back(mat[i][j]);
    vis[i][j] = true;

    for (int d = 0; d < dir1.size(); d++)
    {

        int x = i + dir1[d][0], y = j + dir1[d][1];
        if (isValid(x, y, vis, rmax, cmax))
        {
            dfs(mat, x, y, rmax, cmax, vis, ans);
        }
    }
}

vector<int> travOnMatrix(vector<vector<int>> &mat)
{
    int rmax = mat.size();
    int cmax = mat[0].size();
    vector<vector<bool>> vis(5, vector<bool>(5, false));
    vector<int> ans;
    dfs(mat, 0, 0, rmax, cmax, vis, ans);
    return ans;
}
int main()
{
    vector<vector<int>> mat = {
        {2, 3, 4, 5},
        {31, 61, 52, 40},
        {56, 71, 51, 41}};
    vector<int> ans = travOnMatrix(mat);
    for (auto x : ans)
    {
        cout << x << " ";
    }
}