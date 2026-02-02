class Solution 
{
public:
    int climbStairs(int n) 
    {
         //State -> dp[i] -> Ways to reach Stair i from 0
         //Transition -> dp[i] -> dp[i] = dp[i-1] + dp[i-2]
         //Base Case -> dp[1] = 1 & dp[2] = 2
         //Final Subproblem -> dp[n]

         vector <int> dp(n+1, 0); //State

         //Base Case
         dp[1] = 1;
         if (n > 1)
            dp[2] = 2;
         
         //Transition
         for(int i = 3; i <= n; i++)
            dp[i] = dp[i-1] + dp[i-2];

          return dp[n]; //Final Subproblem 
    }
};
