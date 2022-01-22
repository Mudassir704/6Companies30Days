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
        int y = sum / 2 + 1;
        bool dp[y], dd[y];
        for (int i = 0; i < y; i++)
        {
            dp[i] = dd[i] = false;
        }

        dd[0] = dp[0] = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j + arr[i] < y; j++)
            {
                if (dp[j])
                    dd[j + arr[i]] = true;
            }
            for (int j = 0; j < y; j++)
            {
                if (dd[j])
                    dp[j] = true;
                dd[j] = false;
            }
        }

        for (int i = y - 1; i >= 0; i--)
        {
            if (dp[i])
                return (sum - 2 * i);
        }
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