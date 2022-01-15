#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mod = (1000000007);

public:
    int kvowelwords(int N, int K)
    {
        vector<vector<long long>> dp(N + 1, vector<long long>(K + 1, -1));
        for (int i = 0; i <= K; i++)
            dp[0][i] = 1;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j <= K; j++)
            {
                if (j < K)
                    dp[i][j] = (21 * dp[i - 1][0] + 5 * dp[i - 1][j + 1]) % mod;
                if (j == K)
                    dp[i][j] = (21 * dp[i - 1][0]) % mod;
                if (dp[i][j] < 0)
                    dp[i][j] += mod;
            }
        }
        return dp[N][0] % mod;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        int K;
        cin >> N >> K;

        Solution ob;
        int ans = ob.kvowelwords(N, K);
        cout << ans << endl;
    }
    return 0;
}