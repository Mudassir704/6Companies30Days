#include <bits/stdc++.h>
using namespace std;

// Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
    vector<string> res;
    for (int i = 1; i <= N; i++)
    {
        string s = bitset<64>(i).to_string();
        res.push_back(s.substr(s.find('1')));
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> ans = generate(n);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}