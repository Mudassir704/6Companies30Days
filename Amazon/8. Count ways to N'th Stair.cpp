#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countWays(int m)
    {
        long long res = 0;
        int dp0 = 1;
        int dp1 = 1;
        int dpi = 1;
        for (int i = 2; i <= m; i++)
        {
            dpi = 1 + dp0;
            dp0 = dp1;
            dp1 = dpi;
        }
        return dpi;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m;
        cin >> m;
        Solution ob;
        cout << ob.countWays(m) << endl;
    }
    return 0;
}