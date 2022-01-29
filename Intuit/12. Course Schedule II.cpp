#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> in(numCourses, 0);
        vector<vector<int>> G(numCourses, vector<int>());
        for (vector<int> edge : prerequisites)
        {
            G[edge[1]].push_back(edge[0]);
            in[edge[0]] += 1;
        }
        queue<int> q;
        vector<int> res;
        for (int i = 0; i < numCourses; i++)
            if (in[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            res.push_back(v);
            for (int u : G[v])
            {
                in[u]--;
                if (in[u] == 0)
                    q.push(u);
            }
        }
        if (res.size() == numCourses)
            return res;
        return {};
        // return (res.size() == numCourses ? res : {});
    }
};