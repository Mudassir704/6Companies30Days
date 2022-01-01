#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPosition(int N, int M, int K)
    {
        int res = ((M % N) + K - 1) % N;
        return res == 0 ? N : res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M, K;

        cin >> N >> M >> K;

        Solution ob;
        cout << ob.findPosition(N, M, K) << endl;
    }
    return 0;
}