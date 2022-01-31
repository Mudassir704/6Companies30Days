#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int zerosAtEnd(vector<int> &a)
    {
        int ans = 0;
        int n = a.size();
        int i = n - 1;
        while (i >= 0 && a[i] == 0)
        {
            ans++;
            i--;
        }
        return ans;
    }

    vector<int> gridToVec(vector<vector<int>> &grid)
    {
        vector<int> ans;
        for (auto &x : grid)
        {
            ans.push_back(zerosAtEnd(x));
        }
        return ans;
    }

    int minSwaps(vector<int> &a)
    {
        int n = a.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < (n - i - 1))
            {
                int j = i;
                while (j < n && a[j] < (n - i - 1))
                {
                    j++;
                }

                if (j == n)
                {
                    return -1;
                }
                while (j > i)
                {
                    swap(a[j], a[j - 1]);
                    ans++;
                    j--;
                }
            }
        }
        return ans;
    }

    int minSwaps(vector<vector<int>> &grid)
    {
        vector<int> a = gridToVec(grid);
        return minSwaps(a);
    }
};