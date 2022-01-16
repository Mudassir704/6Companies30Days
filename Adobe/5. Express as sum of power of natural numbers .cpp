#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long numOfWays(int n, int x)
    {
        vector<long long> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        int mx = pow(n, 1.0 / x);
        for (int i = 2; i <= mx; i++)
        {
            int c = pow(i, x);
            for (int j = n; j >= c; j--)
                dp[j] += dp[j - c];
        }
        return dp[n];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        Solution ob;
        cout << ob.numOfWays(n, x) << endl;
    }
    return 0;
}
