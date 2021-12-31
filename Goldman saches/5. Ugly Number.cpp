#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
class Solution
{
public:
    ull getNthUglyNo(int n)
    {
        vector<ull> dp(n + 1, 0);
        dp[1] = 1;
        int p1 = 1, p2 = 1, p3 = 1;
        for (int i = 2; i <= n; i++)
        {
            ull t1 = dp[p1] * 2;
            ull t2 = dp[p2] * 3;
            ull t3 = dp[p3] * 5;
            dp[i] = min(min(t1, t2), t3);
            if (t1 == dp[i])
                p1++;
            if (t2 == dp[i])
                p2++;
            if (t3 == dp[i])
                p3++;
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
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
