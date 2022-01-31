#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &g, int i, int j, int dist = 1)
    {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || (g[i][j] != 0 && g[i][j] <= dist))
            return;
        g[i][j] = dist;
        dfs(g, i - 1, j, dist + 1), dfs(g, i + 1, j, dist + 1), dfs(g, i, j - 1, dist + 1), dfs(g, i, j + 1, dist + 1);
    }
    int maxDistance(vector<vector<int>> &g, int mx = -1)
    {
        for (auto i = 0; i < g.size(); ++i)
            for (auto j = 0; j < g[i].size(); ++j)
                if (g[i][j] == 1)
                {
                    g[i][j] = 0;
                    dfs(g, i, j);
                }
        for (auto i = 0; i < g.size(); ++i)
            for (auto j = 0; j < g[i].size(); ++j)
                if (g[i][j] > 1)
                    mx = max(mx, g[i][j] - 1);
        return mx;
    }
};