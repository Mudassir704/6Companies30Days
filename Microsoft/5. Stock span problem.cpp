#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> calculateSpan(int price[], int n)
    {
        stack<int> s;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && price[s.top()] <= price[i])
                s.pop();
            int len = s.empty() == false ? i - s.top() : i + 1;
            v.push_back(len);
            s.push(i);
        }
        return v;
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
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> s = obj.calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
