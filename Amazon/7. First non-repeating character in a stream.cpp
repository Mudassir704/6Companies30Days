#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        queue<char> q;
        string res = "";
        int freq[26] = {0};
        for (int i = 0; i < A.length(); i++)
        {
            if (freq[A[i] - 'a'] == 0)
                q.push(A[i]);
            freq[A[i] - 'a'] += 1;
            while (!q.empty() && freq[q.front() - 'a'] > 1)
                q.pop();
            if (q.empty())
                res += '#';
            else
                res += q.front();
        }
        return res;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}