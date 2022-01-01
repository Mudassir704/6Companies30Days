#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int CountWays(string s)
    {
        int MOD = (int)(1e9 + 7);
        if (s[0] == '0')
            return 0;
        int last = 1, slast = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '0')
                last = 0;
            if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6')
            {
                last = (last + slast) % MOD;
                slast = (last - slast) % MOD;
                if (last < 0)
                    last += MOD;
                if (slast < 0)
                    slast += MOD;
            }
            else
                slast = last;
        }
        return last;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution obj;
        int ans = obj.CountWays(str);
        cout << ans << "\n";
    }
    return 0;
}