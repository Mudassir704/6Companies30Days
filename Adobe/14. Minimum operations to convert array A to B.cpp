#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int lis(vector<int> arr)
    {
        vector<int> res;
        for (int i = 0; i < arr.size(); i++)
        {
            auto it = lower_bound(res.begin(), res.end(), arr[i]);
            if (it != res.end())
                *it = min(*it, arr[i]);
            else
                res.push_back(arr[i]);
        }
        return res.size();
    }

public:
    int minInsAndDel(int A[], int B[], int N, int M)
    {
        unordered_set<int> b;
        for (int i = 0; i < M; i++)
            b.insert(B[i]);
        vector<int> a;
        int s = 0;
        for (int i = 0; i < N; i++)
        {
            if (b.find(A[i]) != b.end())
                a.push_back(A[i]);
            else
                s++;
        }
        int lis_size = lis(a);
        return (M + N) - 2 * lis_size;
        // return s + (a.size() - lis_size) + (M - lis_size);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;

        int A[N], B[M];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < M; i++)
            cin >> B[i];

        Solution ob;
        cout << ob.minInsAndDel(A, B, N, M) << endl;
    }
    return 0;
}