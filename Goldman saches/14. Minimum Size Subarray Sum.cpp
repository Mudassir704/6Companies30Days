#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int i = 0, j = 0, sum = 0, len = INT_MAX;
    while (j < arr.size())
    {
        sum += arr[j++];
        while (sum >= target)
        {
            len = min(len, j - i);
            sum -= arr[i++];
        }
    }
    int ans = len == INT_MAX ? 0 : len;
    cout << ans << '\n';
}