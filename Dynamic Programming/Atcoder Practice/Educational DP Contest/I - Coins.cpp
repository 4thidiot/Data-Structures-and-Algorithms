#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000009

int main() 
{
	ll n;
	cin >> n;
	vector<double> p(n+1);
    for(int i = 1; i <= n; i++)
        cin >> p[i];

	
	//State -> dp[i][j] = pobability that after tossing first i coins we get exactly j heads
	//Base Case -> dp[0][0] = 1
	//Transition -> dp[i][j] = dp[i-1][j] * (1-p[i]) -> ith coin is tails + dp[i-1][j-1] * p[i] -> ith coin is head
	//Final Subproblem -> sum of dp[n][j] for all j > n/2
	
	vector <vector<double>> dp(n+1, vector <double> (n+1, 0)); //State
	
	dp[0][0] = 1; //Base Case
	
	for(int i=1; i<=n; i++) //Transition
	{
	    for(int j=0; j<=i; j++)
	    {
	        dp[i][j] = dp[i-1][j] * (1-p[i]);
	        dp[i][j] += dp[i-1][j-1] * p[i];
	    }
	}
	
	double ans = 0.0;
    for(int j = (n / 2) + 1; j <= n; j++) //Final Subproblem
        ans += dp[n][j];

    cout << fixed << setprecision(10) << ans << "\n";

}
