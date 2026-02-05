#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9+7;

int main() 
{
	int n, k;
	cin>>n>>k;
	vector <int> v(n);
	for(auto& it : v)
	    cin>>it;
	//State -> dp[x][y] = xth position and y candies, number of ways
	//Base Case -> dp[0][j] = 1 where j is from 0 to v[0]
	//Transition -> dp[x][y] = dp[x-1][y] + dp[x-1][y-1] + dp[x-1][y-2] + ... + dp[x-1][y-a[x]] but here we'll calculate it tc becomes O(n*k*k) therefore since ye last row of y ki value of use kar rhi hai so why not just use prefix array for last row and call it in O(1) time rather than O(k) time.                                                           
	//So for prefix sum                                                      dp[x-1] -> prefix_sum banado corresponding to (each position) of candies Therefore transition looks like dp[x][y] -> prefix_sum[y] - prefix_sum[y-a[x]-1]
	//Final Subproblem -> dp[n-1][k];
	
	vector <vector<int>> dp(100, vector <int> (100005, 0)); //State
	
	for(int j=0; j<=v[0]; j++) //Base Case
	    dp[0][j] = 1;
	    
	for(int i=1; i<n; i++)
	{
	    vector <int> prefix_sum(k+1);
	    prefix_sum[0] = dp[i-1][0];
	    for(int j=1; j<k+1; j++) //creating prefix sum array for each corresponding position index
	        prefix_sum[j] = (prefix_sum[j-1] + dp[i-1][j])%M;
	        
	    for(int j=0; j<k+1; j++)
	    {
	        if(j > v[i])
	            dp[i][j] = (prefix_sum[j] - prefix_sum[j-v[i]-1] + M)%M; //bracket inside term is calculating sum till that index in prefix array
	        else
	            dp[i][j] = prefix_sum[j];
	    }
	}
    
    cout<<dp[n-1][k];
}
