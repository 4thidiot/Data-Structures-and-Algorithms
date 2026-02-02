class Solution {
public:
    int frogJump(vector<int>& heights, int k) 
    {
        //State -> dp[i] = Minimum energy needed to reach step i from start
        //Transition -> dp[i] = min(dp[i-j] + abs(heights[i] - heights[i-j])) where 1 <= j <= k and (i - j) >= 0
        //Base Case -> dp[0] = 0 
        //Final Subproblem -> dp[n-1]
        
        int n = heights.size();
        vector <int> dp(n, INT_MAX); //State and Base Case handled through initialisation

        dp[0] = 0; //Base Case

        for(int i=1; i<n; i++) //Transition
        {
            for(int j=1; j<=k; j++)
                if(i >= j)
                    dp[i] = min ( dp[i], dp[i-j] + abs(heights[i] - heights[i-j]) );
        }
        return dp[n-1]; //Final Subproblem
    }
};
