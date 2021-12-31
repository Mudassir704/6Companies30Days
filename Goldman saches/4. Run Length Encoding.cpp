#include <bits/stdc++.h>
using namespace std;

string encode(string src)
{
    char lastchar = src[0];
    int cnt = 1;
    string res = "";
    for (int i = 1; i < src.length(); i++)
    {
        if (lastchar != src[i])
        {
            res += lastchar;
            res += (to_string(cnt));
            cnt = 1;
            lastchar = src[i];
        }
        else
            cnt++;
    }
    res += lastchar;
    res += (to_string(cnt));
    return res;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;
        cout << encode(str) << endl;
    }
    return 0;
}
