#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve()
{
    ll n, x;
    cin>>n>>x;
    vector <ll> c(n);
    for(auto& it : c)
        cin>>it;
    
    // state -> dp[k] = minimum number of coins to construct sum k
    // transition -> dp[k] = min(dp[k], dp[k-c[j]] + 1) where j is from 1 to n
    // base case -> dp[0] = 1
    // final subproblem -> dp[x]
    
    vector <ll> dp(x+1, INT_MAX); //intitialising with INT_MAX since minimising
    
    dp[0] = 0; //base case

    for(ll i=1; i<=x; i++)
        for(ll j=0; j<n; j++)
            if(i >= c[j]) //imp line
                dp[i] = min( dp[i], dp[i-c[j]] + 1); //transition
    
    cout << (dp[x] != INT_MAX ? dp[x] : -1) << '\n'; //final subproblem
}

int main() 
{
	ll t=1;
// 	cin>>t;
	
	while(t--)
	    solve();
    
    return 0;
}
