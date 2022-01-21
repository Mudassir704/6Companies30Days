#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*You are required to complete this method */
    int atoi(string str)
    {
        int res = 0;
        int st = 0;
        if (str[0] == '-')
            st = 1;
        int p = pow(10, str.length() - 1 - st);
        for (int i = st; i < str.length(); i++)
        {
            int a = str[i] - '0';
            if (a > 9 || a < 0)
                return -1;
            res += a * p;
            p /= 10;
        }
        if (st)
            return res * (-1);
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.atoi(s) << endl;
    }
}