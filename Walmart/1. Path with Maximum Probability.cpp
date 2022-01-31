#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        map<int, vector<pair<int, double>>> G;
        for (int i = 0; i < edges.size(); i++)
        {
            G[edges[i][0]].push_back({edges[i][1], succProb[i]});
            G[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>> q;
        vector<double> prob(n, 0);
        vector<int> vis(n, false);
        q.push({1.0, start});
        while (!q.empty())
        {
            int node = q.top().second;
            double p = q.top().first;
            q.pop();
            if (!vis[node])
            {
                vis[node] = true;
                for (pair<int, double> pair : G[node])
                {
                    if (prob[pair.first] <= p * pair.second)
                    {
                        // cout << pair.first << " " << pair.second << '\n';
                        prob[pair.first] = p * pair.second;
                        q.push({p * pair.second, pair.first});
                    }
                }
            }
        }
        // for(double i: prob)
        //     cout << i << " ";
        return prob[end];
    }
};