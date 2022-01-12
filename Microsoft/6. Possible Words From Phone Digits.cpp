#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution
{

    void getword(int i, int n, int a[], string cur, vector<string> &res, string st[])
    {
        if (i == n)
        {
            res.push_back(cur);
            return;
        }
        string s = st[a[i]];
        for (int j = 0; j < s.size(); j++)
        {
            getword(i + 1, n, a, cur + s[j], res, st);
        }
    }

public:
    vector<string> possibleWords(int a[], int N)
    {
        string st[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        getword(0, N, a, "", res, st);
        return res;
    }
};

int main()
{

    int T;

    cin >> T; // testcases

    while (T--)
    { // while testcases exist
        int N;

        cin >> N; // input size of array

        int a[N]; // declare the array

        for (int i = 0; i < N; i++)
        {
            cin >> a[i]; // input the elements of array that are keys to be pressed
        }

        Solution obj;

        vector<string> res = obj.possibleWords(a, N);
        for (string i : res)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}