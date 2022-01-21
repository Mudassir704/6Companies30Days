// Given two library versions of an executable:
// for example, “10.1.1.3” and “10.1.1.9” or “10” and “10.1”. Find out which one is more recent? Strings can be empty also.

#include <bits/stdc++.h>
using namespace std;

vector<int> tokenize(string s, string del = " ")
{
    int start = 0;
    int end = s.find(del);
    vector<int> str;
    while (end != -1)
    {
        str.push_back(stoi(s.substr(start, end - start)));
        // cout << s.substr(start, end - start) << endl;
        start = end + del.size();
        end = s.find(del, start);
    }
    str.push_back(stoi(s.substr(start, end - start)));
    // cout << s.substr(start, end - start);
    return str;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> a, b;
    a = tokenize(s1, ".");
    b = tokenize(s2, ".");
    int i = 0, j = 0;
    bool f = false;
    while (i < a.size() && j < b.size())
    {
        if (a[i] > b[j])
        {
            cout << s1 << '\n';
            f = true;
            break;
        }
        else if (a[i] < b[j])
        {
            cout << s2 << '\n';
            f = true;
            break;
        }
        else
            i++, j++;
    }
    if (!f)
        cout << "same version" << '\n';
}