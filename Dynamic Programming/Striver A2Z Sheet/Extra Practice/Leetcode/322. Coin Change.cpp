//https://leetcode.com/problems/coin-change/description/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        //State -> dp[i][j] = minimum coins needed to make amount i using coins[0..j]
        //Transition -> dp[i][j] += excluding coin j + including coin j denomination
        //Base Case -> dp[0][j] = 0
        //Final Subproblem -> dp[amount][coins.size()-1] if INF then -1
        const int INF = 1e9;

        int n = coins.size();
        vector <vector<long long>> dp(amount+1, vector <long long> (n, INF)); //State

        for(int j=0; j<n; j++)
            dp[0][j] = 0;

        for(int i=1; i<=amount; i++)
        {
            for(int j=0; j<n; j++)
            {
                if (j == 0)  j == 0 → only coins[0] can be used. // If i is divisible by coins[0], we need i / coins[0] coins; otherwise the amount cannot be formed (INF). Normal DP formula doesn’t work here because j-1 would be invalid.
                {
                    dp[i][j] = (i % coins[0] == 0) ? i / coins[0] : INF;
                    continue;
                }
                long long excl_j = dp[i][j - 1];
                long long inc_j  = (i >= coins[j]) ? dp[i - coins[j]][j] + 1 : INF;

                dp[i][j] = min(excl_j, inc_j);
            }
        }
        return dp[amount][n - 1] == INF ? -1 : dp[amount][n - 1];
    }
};
