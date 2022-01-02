#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        if (nums.size() & 1)
            return false;
        map<int, int> mp;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            mp[nums[i] % k] += 1;
        }
        if ((sum % k) != 0)
            return false;
        for (int i = 0; i < nums.size(); i++)
        {
            int c = (k - (nums[i] % k)) % k;
            if (mp[c] != 0)
                mp[c] -= 1;
            else
                return false;
        }
        return true;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++)
            cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}