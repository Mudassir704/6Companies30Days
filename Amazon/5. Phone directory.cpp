#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> helper(string s, string con[], int n)
    {
        int len = s.length();
        map<string, int> ret;
        for (int i = 0; i < n; i++)
        {
            if (con[i].length() >= len and con[i].substr(0, len) == s)
            {
                ret[con[i]]++;
            }
        }
        vector<string> temp;
        for (auto i : ret)
        {
            temp.push_back(i.first);
        }
        if (temp.size() == 0)
            temp.push_back("0");
        return temp;
    }
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> res;
        for (int i = 1; i <= s.length(); i++)
        {
            vector<string> temp = helper(s.substr(0, i), contact, n);
            res.push_back(temp);
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
        int n;
        cin >> n;
        string contact[n], s;
        for (int i = 0; i < n; i++)
            cin >> contact[i];
        cin >> s;

        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0; i < s.size(); i++)
        {
            for (auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
}