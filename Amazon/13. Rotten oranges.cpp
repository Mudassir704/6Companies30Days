#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int R = grid.size(), C = grid[0].size();
    queue<pair<int, int>> q;
    int fresh = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (grid[i][j] == 2)
                q.push({i, j});
            if (grid[i][j] == 1)
                fresh += 1;
        }
    }
    q.push({-1, -1});
    vector<pair<int, int>> d;
    d.push_back({-1, 0});
    d.push_back({0, 1});
    d.push_back({1, 0});
    d.push_back({0, -1});
    int res = -1;
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if (r == -1)
        {
            res += 1;
            if (!q.empty())
                q.push({-1, -1});
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                int n_r = r + d[i].first, n_c = c + d[i].second;
                if (R > n_r && n_r >= 0 && C > n_c && n_c >= 0)
                {
                    if (grid[n_r][n_c] == 1)
                    {
                        grid[n_r][n_c] = 2;
                        fresh -= 1;
                        q.push({n_r, n_c});
                    }
                }
            }
        }
    }
    if (fresh == 0)
        return res;
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];
        cout << orangesRotting(grid) << '\n';
    }
}