#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dp[501][501];
    int solve(vector<int> arr, int s, int e)
    {
        if (s > e)
            return dp[s][e] = 0;
        if (s == e)
            return dp[s][e] = arr[s];
        if (dp[s][e] != -1)
            return dp[s][e];
        int f = arr[s] + min(solve(arr, s + 1, e - 1), solve(arr, s + 2, e));
        int sec = arr[e] + min(solve(arr, s + 1, e - 1), solve(arr, s, e - 2));
        return dp[s][e] = max(f, sec);
    }

public:
    int maxCoins(vector<int> &A, int n)
    {
        memset(dp, -1, sizeof(dp));
        return solve(A, 0, n - 1);
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
