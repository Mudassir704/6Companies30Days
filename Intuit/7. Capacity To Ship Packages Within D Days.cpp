#include <bits/stdc++.h>
using namespace std;
class Solution
{
    bool isValid(int target, vector<int> weights, int m)
    {
        int cnt = 1, t = 0;
        for (int weight : weights)
        {
            t += weight;
            if (t > target)
            {
                t = weight;
                cnt++;
                if (cnt > m)
                    return false;
            }
        }
        return true;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int sum = 0, mx = INT_MIN;
        for (int weight : weights)
            sum += weight, mx = max(mx, weight);
        int l = mx, r = sum;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (isValid(mid, weights, days))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};