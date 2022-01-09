#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string colName(long long int n)
    {
        string res = "";
        while (n > 0)
        {
            n--;
            char var = 'A' + (n % 26);
            res = var + res;
            n /= 26;
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
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.colName(n) << '\n';
    }
}
// } Driver Code Ends