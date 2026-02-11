class Solution 
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        //State -> dp[i][j] = Unique paths to reach (i,j) from (0,0)
        //Transition -> dp[i][j] = if given[i][j] == 1 then continue else dp[i-1][j] + dp[i][j-1] 
        //Base Case -> dp[0][j] = 1 & dp[i][0] = 1 if no obstacle and dp[0][0] = 1
        //Final Subproblem -> dp[m-1][n-1]

        // If start or end is blocked
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) //Edge Case
            return 0;
            
        vector <vector<int>> dp(m, vector <int> (n, 0)); //State 
        
        dp[0][0] = 1; //Base Case
        // First column - Base Case
        for(int i = 1; i < m; i++)
        {
            if(obstacleGrid[i][0] == 0)
                dp[i][0] = dp[i-1][0];
        }

        // First row - Base Case
        for(int j = 1; j < n; j++)
        {
            if(obstacleGrid[0][j] == 0)
                dp[0][j] = dp[0][j-1];
        }


        for(int i=1; i<m; i++) //Transition
            for(int j=1; j<n; j++)
                if(obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        return dp[m-1][n-1];   //Final Subproblem
    }
};
