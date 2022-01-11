#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int minDifference(int arr[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        vector<vector<bool>> dp(n + 1, vector<bool>((sum / 2) + 1, false));
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum / 2; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = false;
                else if (j == 0)
                    dp[i][j] = true;
                else if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        int i = sum / 2;
        for (; ~i; i--)
            if (dp[n][i])
                break;
        return abs((sum - i) - i);
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

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
}