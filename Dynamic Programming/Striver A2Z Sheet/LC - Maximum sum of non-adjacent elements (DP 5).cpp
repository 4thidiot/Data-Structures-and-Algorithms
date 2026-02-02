class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 0) return 0; //Edge case handling
        if(n == 1) return nums[0];

        //State -> dp[i] = maximum amount of money till house i starting from house 1that can be robbed
        //Transition -> dp[i] = max(dp[i-1], nums[i] + dp[i-2])
        //Base Case -> dp[0] = nums[0], dp[1] = max(nums[0], nums[1])
        //Final Subproblem -> dp[n-1]
        
        vector <int> dp(n, 0); //State

        dp[0] = nums[0]; //Base Case still needed as its for dp
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<n; i++) //Transition
                dp[i] = max(dp[i-1], nums[i] + dp[i-2]);

        return dp[n-1]; //Final Subproblem
    }
};
