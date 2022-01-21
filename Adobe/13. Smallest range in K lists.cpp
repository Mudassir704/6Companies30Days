#include <bits/stdc++.h>
using namespace std;
#define N 1000

class Box
{
public:
    int num;
    int numIdx;
    int arrIdx;

    Box(int _num, int _numIdx, int _arrIdx)
    {
        num = _num;
        numIdx = _numIdx;
        arrIdx = _arrIdx;
    }
};

struct comp
{
    bool operator()(const Box &x, const Box &y) const
    {
        if (x.num == y.num)
            return x.arrIdx < y.arrIdx;
        return x.num < y.num;
    }
};
class Solution
{
public:
    pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        set<Box, comp> s;
        for (int i = 0; i < k; i++)
        {
            Box b(KSortedArray[i][0], 0, i);
            s.insert(b);
        }
        pair<int, int> range = {0, 1e5};
        while (1)
        {
            auto l = *s.begin(), r = *s.rbegin();
            int currD = r.num - l.num, prevD = range.second - range.first;
            if (currD < prevD)
                range = {l.num, r.num};
            int currIdx = l.numIdx;
            if (currIdx == n - 1)
                break;
            s.erase(s.begin());
            l.numIdx = currIdx + 1;
            l.num = KSortedArray[l.arrIdx][l.numIdx];
            s.insert(l);
        }
        return range;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[N][N];
        pair<int, int> rangee;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        rangee = obj.findSmallestRange(arr, n, k);
        cout << rangee.first << " " << rangee.second << "\n";
    }
    return 0;
}
