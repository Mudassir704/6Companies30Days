#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string amendSentence(string s)
    {
        string res = "";
        res += tolower(s[0]);
        for (int i = 1; i < s.length(); i++)
        {
            if (isupper(s[i]))
            {
                res += " ";
                res += tolower(s[i]);
            }
            else
                res += s[i];
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
        string s;
        cin >> s;
        Solution ob;
        cout << ob.amendSentence(s) << endl;
    }
}