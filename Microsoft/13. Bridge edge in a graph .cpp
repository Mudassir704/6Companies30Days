#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d)
    {

        adj[c].erase(find(adj[c].begin(), adj[c].end(), d));
        adj[d].erase(find(adj[d].begin(), adj[d].end(), c));
        vector<bool> vis(V, false);
        stack<int> s;
        s.push(c);
        vis[c] = true;
        while (!s.empty())
        {
            int t = s.top();
            s.pop();
            vis[t] = true;
            for (int a : adj[t])
                if (!vis[a])
                    s.push(a);
        }
        if (vis[d])
            return 0;
        return 1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}
