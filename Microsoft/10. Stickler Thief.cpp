#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        int pre = 0, cur = 0;
        for (int i = 0; i < n; i++)
        {
            int t = max(cur, pre + arr[i]);
            pre = cur;
            cur = t;
        }
        return cur;
    }
};

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking number of houses
        int n;
        cin >> n;
        int a[n];

        // inserting money of each house in the array
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;
        // calling function FindMaxSum()
        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}
