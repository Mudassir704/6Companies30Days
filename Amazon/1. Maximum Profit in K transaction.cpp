#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        if(K >= N / 2){
            int maxProfit = 0;
            for(int i = 1;i < N;i++)
                if(A[i] > A[i - 1])
                    maxProfit += (A[i] - A[i - 1]);
            return maxProfit;
        }
        vector<int> dp(N, 0), dp1(N, 0);
        for(int i = 1;i <= K;i++){
            int max_so = INT_MIN;
            for(int j = 1;j < N;j++){
                max_so = max(max_so, dp1[j - 1] - A[j - 1]);
                dp[j] = max(dp[j - 1], max_so + A[j]);
            }
            dp1 = dp;
        }
        return dp[N - 1];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  