#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int isValid(int target, vector<int> nums, int m)
    {
        int t = 0, cnt = 1;
        for (int num : nums)
        {
            t += num;
            if (t > target)
            {
                t = num;
                cnt++;
                if (cnt > m)
                    return false;
            }
        }
        return true;
    }

public:
    int splitArray(vector<int> &nums, int m)
    {
        int sum = 0, mx = INT_MIN;
        for (int num : nums)
            sum += num, mx = max(mx, num);
        int l = mx, r = sum;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (isValid(mid, nums, m))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};