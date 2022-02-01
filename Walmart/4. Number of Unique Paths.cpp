#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        if (a == 1 || b == 1)
            return 1;
        return NumberOfPath(a - 1, b) + NumberOfPath(a, b - 1);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        Solution ob;
        cout << ob.NumberOfPath(a, b) << endl;
    }
}
