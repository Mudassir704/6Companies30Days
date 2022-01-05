#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 3)
            return 0;
        int up = 0, down = 0, res = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] == arr[i] || (down && arr[i - 1] < arr[i]))
                down = up = 0;
            if (arr[i - 1] > arr[i])
                down++;
            if (arr[i - 1] < arr[i])
                up++;
            if (down && up)
                res = max(res, up + down + 1);
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
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.longestMountain(A) << endl;
    }
    return 0;
}