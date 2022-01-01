#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string printMinNumberForPattern(string S)
    {
        int num = 1;
        stack<int> s;
        string res = "";
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == 'I')
            {
                s.push(num++);
                while (!s.empty())
                {
                    res += to_string(s.top());
                    s.pop();
                }
            }
            else
                s.push(num++);
        }
        s.push(num++);
        while (!s.empty())
        {
            res += to_string(s.top());
            s.pop();
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0;
}
