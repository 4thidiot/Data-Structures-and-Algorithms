#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

vector <vector<int>> dp(1e6 + 1, vector <int> (2, 0)); //Globally defining the dp array because why assign new space for each testcase just assign it once
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    //State -> 
	    // dp[i][0] = Number of ways to go from ith row to (n-1)th row such that there is a horizontal block trying to extend from the (i-1)th row
	    //dp[i][1] = Number of ways to go from ith row to (n-1)th row such that there is are 2 vertical blocks trying to extend from the (i-1)th row
	    
	    //Transition -> 
	    //dp[i][0] = 2*dp[i+1][0] + dp[i+1][1]
	    //dp[i][1] = 4*dp[i+1][1] + dp[i+1][0]
	    
	    //Base Case -> since reached end so we cant extend forward so just close it
	    //dp[n][0] = 1 
	    //dp[n][1] = 1
	    
	    //Final Subproblem -> dp[1][0] + dp[1][1]
	    
	    dp[n][0] = 1;
	    dp[n][1] = 1;
	    
	    for(int i = n-1; i>=0; i--)
	    {
	        dp[i][0] = (2LL*dp[i+1][0] + dp[i+1][1]) % MOD;
	        dp[i][1] = (4LL*dp[i+1][1] + dp[i+1][0]) % MOD;
	    }
	    
	    cout << (dp[1][0] + dp[1][1]) % MOD << '\n';
	}

}
