#include <bits/stdc++.h>
using namespace std;



class Solution
{
    string mx = "";
    public:
    void solve(string str, int k, int idx){
        if(k == 0)
            return;
        char mxChar = str[idx];
        for(int i = idx + 1;i < str.length();i++)
            mxChar = max(mxChar, str[i]);
            
        if(mxChar != str[idx])
            k--;
            
        for(int i = idx;i < str.length();i++){
            if(str[i] == mxChar){
                swap(str[idx], str[i]);
                mx = max(mx, str);
                solve(str, k, idx + 1);
                swap(str[idx], str[i]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
        mx = str;
       if(k == 0)
            return mx;
        solve(str, k, 0);

        return mx;
    }
};


int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}