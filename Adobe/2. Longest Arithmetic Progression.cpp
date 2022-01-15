#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestAP(int A[], int n)
    {
        if (n == 1)
            return 1;
        vector<vector<int>> dp(n, vector<int>(10001));
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int d = A[j] - A[i];
                dp[j][d] = max(dp[i][d] + 1, 2);
                ans = max(ans, dp[j][d]);
            }
        }
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
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}