#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int height(int N)
    {
        int i = 0;
        for (i = 1; i < 1000; i++)
        {
            if (((i * (i + 1)) / 2) > N)
                break;
        }
        return i - 1;
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

        Solution ob;
        cout << ob.height(N) << endl;
    }
    return 0;
}