#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int solve(vector<int> &piles, int i, int j, vector<vector<int>> &dp)
    {
        if (i == j)
            return piles[i];
        if (j - i == 1)
            return dp[i][j] = max(piles[i], piles[j]);
        if (dp[i][j] != -1)
            return dp[i][j];
        if (dp[i + 1][j - 1] == -1)
            dp[i + 1][j - 1] = solve(piles, i + 1, j - 1, dp);

        if (dp[i + 2][j] == -1)
            dp[i + 2][j] = solve(piles, i + 2, j, dp);

        if (dp[i][j - 2] == -1)
            dp[i][j - 2] = solve(piles, i, j - 2, dp);

        int f = piles[i] + max(dp[i + 1][j - 1], dp[i + 2][j]);
        int s = piles[j] + max(dp[i + 1][j - 1], dp[i][j - 2]);
        return dp[i][j] = max(f, s);
    }

public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int s = 0;
        for (int i : piles)
            s += i;
        int AliceCount = solve(piles, 0, piles.size() - 1, dp);
        return AliceCount > (s - AliceCount);
        // return true;
    }
};