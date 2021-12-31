#include <bits/stdc++.h>
using namespace std;

string gcdOfStrings(string str1, string str2)
{
    int m = str1.length();
    int n = str2.length();
    if (str1 + str2 == str2 + str1)
        return str1.substr(0, __gcd(n, m));
    return "";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str1, str2;
        cin >> str1 >> str2;
        cout << gcdOfStrings(str1, str2) << '\n';
    }
}