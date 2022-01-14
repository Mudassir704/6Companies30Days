#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSteps(int D)
    {
        int s = 0, step = 0;
        while (true)
        {
            s += step;
            step++;
            if (s == D)
                break;
            if (s > D and ((s - D) & 1) == 0)
                break;
        }
        return step - 1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int D;
        cin >> D;

        Solution ob;
        cout << ob.minSteps(D) << "\n";
    }
    return 0;
}