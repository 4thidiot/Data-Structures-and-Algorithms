class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int m = triangle.size();

        //State -> dp[i][j] = Minimum sum path to (i,j) from (0,0)
        //Transition -> dp[i][j] = min(dp[i][j-1], dp[i-1][j-1]) + triangle[i][j] and edge cases of leftmost and right most
        //Base Case -> dp[0][0] = triangle[0][0]
        //Final Subproblem -> dp[m-1][n-1]

        vector <vector<int>> dp(m);
        for(int i=0; i<m; i++)
            dp[i].resize(i+1);

        dp[0][0] = triangle[0][0]; //Base Case

        for(int i=0; i<m; i++) //Transition
        {   
            for(int j=0; j<=i; j++)
             {
                 if(j == 0)
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                else if(j == i)
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                else
                    dp[i][j] = triangle[i][j] + 
                               min(dp[i-1][j-1], dp[i-1][j]);
             }
        }

        int ans = INT_MAX; //Final Subproblem
        for(int j = 0; j < m; j++)
            ans = min(ans, dp[m-1][j]);

        return ans; 
    }
};
