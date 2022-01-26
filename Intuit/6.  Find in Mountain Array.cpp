#include <bits/stdc++.h>
using namespace std;
class MountainArray
{
public:
    int get(int index);
    int length();
};
class Solution
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int len = mountainArr.length();
        int l = 0, r = len - 1;
        unordered_map<int, int> mp;
        while (l < r)
        {
            int mid = (l + r) / 2;
            int midEle = (mp.find(mid) == mp.end()) ? mountainArr.get(mid) : mp[mid];
            int midnext = (mp.find(mid + 1) == mp.end()) ? mountainArr.get(mid + 1) : mp[mid + 1];
            if (midEle < midnext)
                l = mid + 1;
            else
                r = mid;
        }
        int peak = l;
        l = 0, r = peak;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int midEle = (mp.find(mid) == mp.end()) ? mountainArr.get(mid) : mp[mid];
            if (midEle == target)
                return mid;
            else if (midEle > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        l = peak + 1, r = len - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int midEle = (mp.find(mid) == mp.end()) ? mountainArr.get(mid) : mp[mid];
            if (midEle == target)
                return mid;
            else if (midEle > target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};