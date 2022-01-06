#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[30][30], dp_idx[30][30];
    string ans;
    char var;
    void print(int i, int j)
    {
        if (i == j)
        {
            ans += (var++);
            return;
        }
        ans += '(';
        print(i, dp_idx[i][j]);
        print(dp_idx[i][j] + 1, j);
        ans += ')';
    }
    int solve(int arr[], int i, int j)
    {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int res = INT_MAX, idx;
        for (int k = i; k < j; k++)
        {
            dp[i][k] = dp[i][k] == -1 ? solve(arr, i, k) : dp[i][k];
            dp[k + 1][j] = dp[k + 1][j] == -1 ? solve(arr, k + 1, j) : dp[k + 1][j];
            int temp = dp[i][k] + dp[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]);
            if (temp < res)
                res = temp, idx = k;
        }
        dp_idx[i][j] = idx;
        return dp[i][j] = res;
    }
    string matrixChainOrder(int p[], int n)
    {
        ans = "";
        var = 'A';
        memset(dp, -1, sizeof(dp));
        memset(dp_idx, -1, sizeof(dp_idx));
        solve(p, 1, n - 1);
        print(1, n - 1);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i];

        Solution ob;
        cout << ob.matrixChainOrder(p, n) << "\n";
    }
    return 0;
}