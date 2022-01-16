#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n);

class Solution
{
    vector<string> res;
    void gen(string &s, int open, int close)
    {
        if (open == 0 && close == 0)
        {
            res.push_back(s);
            return;
        }
        if (open > 0)
        {
            s.push_back('(');
            gen(s, open - 1, close);
            s.pop_back();
        }
        if (close > 0)
        {
            if (open < close)
            {
                s.push_back(')');
                gen(s, open, close - 1);
                s.pop_back();
            }
        }
    }

public:
    vector<string> AllParenthesis(int n)
    {
        // Your code goes here
        string s = "";
        gen(s, n, n);
        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<string> result = ob.AllParenthesis(n);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << "\n";
    }
    return 0;
}
