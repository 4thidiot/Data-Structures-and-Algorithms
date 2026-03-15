#define ll long long
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        
        //State -> dp[i][j] = side length of the largest square whose bottom-right corner is at cell (i, j)
        //Transition -> dp[i][j] = 1 + min(dp[left], dp[top], dp[top left]) if(matrix[i][j]==1)
        //Base Case -> dp[0][j] = matrix[0][j] && dp[i][j] = matrix[i][j] 
        //Final Subproblem -> max in dp array * max in dp array
        int ans = 0;
        vector <vector <ll>> dp(n, vector <ll> (m, 0)); //State 

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == '1')
                {
                    if(i == 0 || j == 0) // Base case
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}); //Transition

                    ans = max(ans, (int)dp[i][j]);
                }
            }
        }
        return ans*ans; //Final Subproblem
    }
};
