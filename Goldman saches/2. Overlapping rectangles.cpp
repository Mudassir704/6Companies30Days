#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p[2], q[2], r[2], s[2];
    cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
    if (p[0] > s[0] || r[0] > q[0] || q[1] > r[1] || s[1] > p[1])
        cout << 0 << '\n';
    else
        cout << 1 << "\n";
}