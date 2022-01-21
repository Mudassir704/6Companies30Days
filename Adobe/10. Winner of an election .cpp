#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[], int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        map<string, int> mp;
        for (int i = 0; i < n; i++)
            mp[arr[i]] += 1;
        int mx = 0;
        string s;
        for (auto i : mp)
        {
            if (i.second > mx)
            {
                mx = i.second;
                s = i.first;
            }
        }
        string vote = to_string(mx);
        return {s, vote};
    }
};

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int n;
        cin >> n;

        string arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr, n);

        cout << result[0] << " " << result[1] << endl;
    }
    return 0;
}
