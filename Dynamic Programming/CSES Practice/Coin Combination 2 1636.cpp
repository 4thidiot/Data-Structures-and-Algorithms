#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector <int> c(n);
    for(auto& it : c)
        cin >> it;
    
    // state -> dp[i][k] = no of ways to get a sum of k such that all coins from ci to cn are pickable ands all coins before ci are skipped
    // transition -> see nb
    // base case -> dp[i][0] = 1 since only 1 way to get 0 sum irrespective of i range
    // final subproblem -> dp[1][x] basically number of ways to get a sum k=x
    
    vector <vector<int>> dp(n+1, vector <int> (x+1)); //State here coins are from 0 to n-1 while in copy its from 1 to n 
//vector type int rakho since already v huge borderline memory so ll avoid
    
    for(int i=0; i<n; i++) //Base Case
        dp[i][0] = 1;
    
    for(int i=n-1; i>=0; i--) //Transition
    {
        for(int sum=1; sum<=x; sum++)
        {
            ll skipping = dp[i+1][sum];
            ll picking = 0;
            if(sum>=c[i])
                picking = dp[i][sum-c[i]];
            dp[i][sum] = (skipping + picking) % MOD;
        }
    }
    
    cout << dp[0][x] << '\n'; //Final Subproblem
}

int main() 
{
	int t=1;
// 	cin>>t;
	
	while(t--)
	    solve();

}
