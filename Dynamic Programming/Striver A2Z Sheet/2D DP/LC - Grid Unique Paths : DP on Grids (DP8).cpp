class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        //State -> dp[i][j] = Unique paths to reach (i,j) from (0,0)
        //Transition -> dp[i][j] = dp[i-1][j] + dp[i][j-1]
        //Base Case -> dp[0][j] = 1 & dp[i][0] = 1
        //Final Subproblem -> dp[m-1][n-1]

        vector <vector<int>> dp(m, vector <int> (n, 0)); //State 
        
        // Base Case
        for(int i = 0; i < m; i++)
            dp[i][0] = 1;
            
        for(int j = 0; j < n; j++)
            dp[0][j] = 1;

        for(int i=1; i<m; i++)        //Transition
            for(int j=1; j<n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        return dp[m-1][n-1];   //Final Subproblem
    }
};
