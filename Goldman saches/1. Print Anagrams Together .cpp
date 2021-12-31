#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    unordered_map<string, vector<string>> mp;
    for (int i = 0; i < n; i++)
    {
        string sortedString = arr[i];
        sort(sortedString.begin(), sortedString.end());
        mp[sortedString].push_back(arr[i]);
    }
    for (auto i : mp)
    {
        for (string j : i.second)
            cout << j << " ";
        cout << '\n';
    }
    return 0;
}