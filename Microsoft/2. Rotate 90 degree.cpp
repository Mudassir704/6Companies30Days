#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &matrix);

void rotate(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    for (int i = 0; i < n; i++)
        for (int j = i; j < m; j++)
            swap(a[i][j], a[j][i]);

    for (int i = 0; i < n / 2; i++)
        swap(a[i], a[n - i - 1]);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n);
        for (int i = 0; i < n; i++)
        {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }
    }
    return 0;
}
