//https://leetcode.com/problems/coin-change-ii/description/
class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        //State -> dp[i][j] = Number of ways to form amount i using first j coins
        //Transition -> dp[i][j] += excluding coin j + including coin j denomination
        //Base Case -> dp[0][j] = 1 
        //Final Subproblem -> dp[amount][coins.size()-1]

        int n = coins.size();
        const long long LIM = 1e18;
        vector <vector<long long>> dp(amount+1, vector <long long> (n, 0)); //State

        for(int j=0; j<n; j++)
            dp[0][j] = 1;

        for(int i=1; i<=amount; i++)
        {
            for(int j=0; j<n; j++)
            {
                long long excl_j = (j >=1 ) ? dp[i][j-1] : 0;
                long long inc_j = (i >= coins[j]) ? dp[i-coins[j]][j] : 0;
                dp[i][j] = min(LIM, excl_j + inc_j);
            }
        }
        return dp[amount][n-1];
    }
};
