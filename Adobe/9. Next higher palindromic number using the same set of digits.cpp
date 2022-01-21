#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string nextPalin(string N)
    {
        int len = N.length();
        if (len <= 3)
            return "-1";
        string f = N.substr(0, len / 2), prev = f;
        next_permutation(f.begin(), f.end());
        if (prev >= f)
            return "-1";
        string res = f;
        string s = f;
        reverse(s.begin(), s.end());
        if (len & 1)
            res += N[(len / 2)];
        res += s;
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
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}