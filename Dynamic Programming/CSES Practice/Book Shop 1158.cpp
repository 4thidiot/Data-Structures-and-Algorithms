#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main() 
{
	// State -> dp[i][j] = max value/books that we can get for the prefix of length i such that the allowed capacity/pages is j 
	// Base Case -> dp[0][anything] = 0
	// Transition -> dp[i][j] = max(skip, pick) where skip is dp[i-1][w] and pick is value[i] + dp[i-1][j-weight]
    // Final Subproblem -> dp[n][x]
    
    int n, x;
    cin>>n>>x;
    vector <int> val(n), weight(n);
    
    for(int i=0; i<n; i++)
        cin>>weight[i];
    for(int i=0; i<n; i++)
        cin>>val[i];
    
    vector <vector<int>> dp(n+1, vector <int> (x+1, 0)); //State and also Base Case Handled here too
    for(int i=1; i<=n; i++)
    {
        for(int j=x; j>=0; j--)
        {
            int w = weight[i-1];
            int value = val[i-1];
            
            int pick = (j>=w ? dp[i-1][j-w] + value : 0);
            int skip = dp[i-1][j];
            
            dp[i][j] = max(skip, pick); //Transition
        }
    }
    
    cout<<dp[n][x]<<'\n'; //Final Subproblem
    
    return 0;
}
