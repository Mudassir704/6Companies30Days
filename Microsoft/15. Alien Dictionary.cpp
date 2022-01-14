#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void DFS_sort(map<char, vector<char>> &Adj, set<char> &visited, char v, string &order)
    {
        visited.insert(v);
        for (auto u : Adj[v])
            if (!visited.count(u))
                DFS_sort(Adj, visited, u, order);
        order = v + order;
    }
    string findOrder(string dict[], int N, int K)
    {
        map<char, vector<char>> Adj;
        auto compare = [&Adj](string &s1, string &s2)
        {
            for (int i = 0; i < s1.size() && i < s2.size(); i++)
            {
                if (s1[i] != s2[i])
                {
                    Adj[s1[i]].push_back(s2[i]);
                    return;
                }
            }
        };

        for (int i = 0; i < N - 1; i++)
        {
            compare(dict[i], dict[i + 1]);
        }

        string ans;
        set<char> visited;
        for (auto p : Adj)
        {
            if (!visited.count(p.first))
                DFS_sort(Adj, visited, p.first, ans);
        }

        return ans;
    }
};

string order;
bool f(string a, string b)
{
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++)
    {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}
