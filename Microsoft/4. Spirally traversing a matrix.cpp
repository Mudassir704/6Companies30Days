#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> a, int r, int c)
    {
        int rl = 0, rh = r - 1;
        int cl = 0, ch = c - 1;
        vector<int> dp;
        int count = 0;
        while (rl <= rh && cl <= ch)
        {
            for (int i = cl; i <= ch; i++)
            {
                dp.push_back(a[rl][i]);
            }
            rl++;
            for (int i = rl; i <= rh; i++)
            {
                dp.push_back(a[i][ch]);
            }
            ch--;
            if (rl <= rh)
            {
                for (int i = ch; i >= cl; i--)
                {
                    dp.push_back(a[rh][i]);
                }
                rh--;
            }
            if (cl <= ch)
            {
                for (int i = rh; i >= rl; i--)
                {
                    dp.push_back(a[i][cl]);
                }
                cl++;
            }
        }
        return dp;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}