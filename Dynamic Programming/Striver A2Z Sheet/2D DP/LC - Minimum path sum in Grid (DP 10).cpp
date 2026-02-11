class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size(); //no of rows
        int n = grid[0].size(); //no of columns in first row

        //State -> dp[i][j] = Minimum sum path from (0,0) to (i,j)
        //Transition -> dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
        //Base Case -> dp[0][0] = grid[0][0] & dp[i][0] and dp[0][j]
        //Final Subproblem -> dp[m-1][n-1]

        vector <vector<int>> dp(m, vector <int> (n, INT_MAX));

        //Base Case
        dp[0][0] = grid[0][0];
        // First column
        for(int i = 1; i < m; i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];

        // First row
        for(int j = 1; j < n; j++)
            dp[0][j] = dp[0][j-1] + grid[0][j];

        for(int i=1; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(j>0)
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[m-1][n-1]; //Finals Subproblem
    }
};
