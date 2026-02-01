#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;

int main() 
{
	ll n, m;
	cin>>n>>m;
	vector <ll> v(n+1, 0);
	for(int i=1; i<=n; i++)
	    cin>>v[i];
	    
// 	State -> dp[i][j] = Number of valid arrays of size i such that last element is j
// 	Transition -> dp[i][j] = 0 if(v[i]!=0 && v[i]!=j) else dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]
// 	Base Case -> dp[1][j] = 0 (if(v[0]!=0) && v[0]!=j) else = i
// 	Final Subproblem -> dp[n][1] + dp[n][2] + ... + dp[n][m];
	
	vector <vector<ll>> dp(n+1, vector <ll> (m+1, 0)); //State and 0 waala part of base case also handled here through initialisation
	
	for(int j=1; j<=m; j++) //Base Case
	{
	    if(v[1]==0 || v[1]==j)
	        dp[1][j] = 1;
	    else //Although handled in state line initialisation
	        dp[1][j] = 0;
	}
	
	for(int i=2; i<=n; i++) //Transition
	{
	    for(int j=1; j<=m; j++)
	    {
	        if(v[i]!=0 && v[i]!=j)
	            dp[i][j] = 0;
	        else
	        {
	            ll ways = dp[i-1][j];
                if(j-1 >= 1) ways += dp[i-1][j-1];
                if(j+1 <= m) ways += dp[i-1][j+1];
                dp[i][j] = ways % mod;

	        }
	    }
	}
    
    ll ans = 0;
    for(int j=1; j<=m; j++)
        ans = (ans + dp[n][j])%mod;
        
    cout<<ans<<'\n';
    
    return 0;
}
