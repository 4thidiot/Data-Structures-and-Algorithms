class Solution {
public:
    int frogJump(vector<int>& heights) 
    {
        //State -> dp[i] = Minimum energy needed to reach step i from start
        //Transition -> dp[i] = min( dp[i-1] + abs(heights[i] - heights[i-1]), dp[i-2] + abs(heights[i] - heights[i-2]) )
        //Base Case -> dp[0] = 0 and dp[1] = abs(heights[1] - heights[0])
        //Final Subproblem -> dp[n-1]
        
        int n = heights.size();
        vector <int> dp(n, 0); //State and 1st part of Base Case handled through initialisation

        dp[1] = abs(heights[1] - heights[0]); //Base Case

        for(int i=2; i<n; i++) //Transition
            dp[i] = min( dp[i-1] + abs(heights[i] - heights[i-1]), dp[i-2] + abs(heights[i] - heights[i-2]) );
        
        return dp[n-1]; //Final Subproblem
    }
};
