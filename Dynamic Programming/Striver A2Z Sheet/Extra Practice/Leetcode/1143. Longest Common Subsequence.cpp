class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n = text1.length();
        int m = text2.length();
        //State -> dp[i][j] = LCS till ith index of text1 and jth index of text2
        //Transition -> dp[i][j] = 1+dp[i−1][j−1] ( if(text1[i]==text2[j]) ) else = max(dp[i−1][j],dp[i][j−1])
        //Base Case -> dp[0][m] = dp[n][0] = 0 where m is 0 to m and n is 0 to n
        //Final Subproblem -> dp[n][m]

        vector <vector<int>> dp(n+1, vector <int> (m+1, 0)); //State and Base Case is handled here through initialisation

        for(int i=1; i<=n; i++) //Transition
        {
            for(int j=1; j<=m; j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m]; //Final Subproblem
    }
};
