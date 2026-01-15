#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

void solve()
{
    ll n, x;
    cin >> n >> x;
    vector <ll> c(n);
    for(auto& it : c)
        cin >> it;
    
    // state -> dp[k] = number of ways to get a sum k
    // transition -> dp[k] = dp[k]+dp[k-c[j]] where j is from 1:n (no +1 here since number of ways and not number of coins)
    // base case -> dp[0] = 1 since only 1 way to get 0 sum
    // final subproblem -> dp[x] basically number of ways to get a sum k=x
    
    vector <ll> dp(x+1, 0); //no need to initialise since only ways asked and not min max but rather inintiliase with 0 waise by default its 0 only
    
    dp[0] = 1; //Base Case
    for(int i = 1; i <= x; i++)
        for(int j = 0; j < n; j++)
            if(i >= c[j]) //V imp!
                dp[i] = (dp[i] + dp[i-c[j]]) % MOD; //Transition
                
    cout << dp[x] << '\n'; //Final Subproblem
}

int main() 
{
	int t=1;
// 	cin>>t;
	
	while(t--)
	    solve();

}
