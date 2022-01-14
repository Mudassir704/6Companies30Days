#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        for (int i = 0; i < arr.size() - 2; i++)
        {
            for (int j = i + 1; j < arr.size() - 1; j++)
            {
                int l = j + 1;
                int h = arr.size() - 1;
                while (l < h)
                {
                    int t = arr[i] + arr[j] + arr[l] + arr[h];
                    // cout << t << " ";
                    if (t == k)
                    {
                        vector<int> v = {arr[i], arr[j], arr[l], arr[h]};
                        res.push_back(v);
                        l++, h--;
                    }
                    else if (t > k)
                    {
                        h--;
                    }
                    else
                        l++;
                }
            }
        }
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.fourSum(a, k);
        for (auto &v : ans)
        {
            for (int &u : v)
            {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty())
        {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}