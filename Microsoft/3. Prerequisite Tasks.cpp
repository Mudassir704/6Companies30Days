#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int N, vector<pair<int, int>> &prerequisites)
    {
        vector<int> g[N];
        for (auto &i : prerequisites)
            g[i.first].push_back(i.second);
        vector<int> in(N, 0);
        for (int i = 0; i < N; i++)
            for (int v : g[i])
                in[v]++;
        queue<int> q;
        for (int i = 0; i < N; i++)
            if (in[i] == 0)
                q.push(i);
        int cnt = 0;
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            cnt++;
            for (int i : g[t])
            {
                in[i]--;
                if (in[i] == 0)
                    q.push(i);
            }
        }
        return (cnt == N);
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}