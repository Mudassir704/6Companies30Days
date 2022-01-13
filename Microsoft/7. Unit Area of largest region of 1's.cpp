#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    void dfs(vector<vector<bool>> &vis, vector<vector<int>> &grid, int i, int j, int &cnt)
    {
        cnt++;
        vis[i][j] = true;
        for (int t = 0; t < 8; t++)
        {
            int x = i + dir[t].first;
            int y = j + dir[t].second;
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && !vis[x][y] && grid[x][y])
                dfs(vis, grid, x, y, cnt);
        }
    }

public:
    // Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int res = INT_MIN;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j])
                {
                    int cnt = 0;
                    dfs(vis, grid, i, j, cnt);
                    // cout << cnt << '\n';
                    res = max(res, cnt);
                }
            }
        }
        return res;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.findMaxArea(grid);
        cout << ans << "\n";
    }
    return 0;
}