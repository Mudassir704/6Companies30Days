#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(vector<vector<int>> &isConnected, vector<int> &vis, int i)
    {
        vis[i] = true;
        for (int x = 0; x < vis.size(); x++)
            if (i != x && isConnected[i][x] && !vis[x])
                dfs(isConnected, vis, x);
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> vis(n, false);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(isConnected, vis, i);
            }
        }
        return cnt;
    }
};