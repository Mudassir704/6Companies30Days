#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int st = 0, cur = 0;
        for (int e = 0; e < n; e++)
        {
            cur += arr[e];
            while (cur > s)
            {
                cur -= arr[st];
                st++;
            }
            if (cur == s)
                return {st + 1, e + 1};
        }
        return {-1};
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long s;
        cin >> n >> s;
        int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}