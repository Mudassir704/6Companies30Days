#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<pair<int, int>> df = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void dfs(vector<vector<int>> &heights, vector<vector<int>> &vis, int h, int i, int j)
    {
        if (i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || vis[i][j] || heights[i][j] < h)
            return;
        vis[i][j] = true;
        for (auto d : df)
        {
            int x = i + d.first;
            int y = j + d.second;
            dfs(heights, vis, heights[i][j], x, y);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        vector<vector<int>> res;
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> P(m, vector<int>(n, false));
        vector<vector<int>> A(m, vector<int>(n, false));
        for (int i = 0; i < m; i++)
        {
            dfs(heights, P, INT_MIN, i, 0);
            dfs(heights, A, INT_MIN, i, n - 1);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(heights, P, INT_MIN, 0, i);
            dfs(heights, A, INT_MIN, m - 1, i);
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (P[i][j] && A[i][j])
                    res.push_back({i, j});
        return res;
    }
};