#include <bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string &str);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << missingNumber(str) << endl;
    }
    return 0;
}
// } Driver Code Ends

/* You are required to complete this function
which return the required missing number
if present else return -1*/
long long sto(string s)
{
    long long x = 0;
    for (int i = 0; i < s.size(); i++)
        x = x * 10 + s[i] - '0';
    return x;
}
int missingNumber(const string &str)
{
    int n = str.size();
    for (int len = 1; len <= 6; len++)
    {
        string temp = "";
        for (int i = 0; i < len; i++)
            temp += str[i];
        int j = len;
        long long p = sto(temp), miss, cnt = 0, f = 0;
        // cout << p << " ";
        temp = "";
        while (j < n)
        {
            temp += str[j++];
            int c = sto(temp);
            // cout << c << " ";
            if (p + 1 == c)
            {
                p = c;
                temp = "";
            }
            else if (p + 2 == c)
            {
                cnt++;
                miss = p + 1;
                p = c;
                temp = "";
            }
            else if (p < c)
                f = 1;
        }
        if (cnt == 1 && !f)
            return miss;
        // cout << '\n';
    }
    return -1;
}