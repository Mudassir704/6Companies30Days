#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        int *a = new int[2];
        int i = 0;
        while (i < n)
        {
            while ((i < n) && (arr[i] != arr[arr[i] - 1]))
                swap(arr[arr[i] - 1], arr[i]);
            i++;
        }

        for (int i = 0; i < n; i++)
            if (arr[i] != i + 1)
                a[0] = arr[i], a[1] = i + 1;
        return a;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}