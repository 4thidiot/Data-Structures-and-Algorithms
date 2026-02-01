#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

int main()
{
    ll n, w;
    cin >> n >> w;

    // 1 based indexing
    vector<ll> weight(n+1), value(n+1);
    for(ll i = 1; i <= n; i++)
        cin >> weight[i] >> value[i];

    ll MAXV = 100000;

    // State -> dp[i][j] = minimum weight required to get
    //          total value exactly equal to j
    //          using prefix of length i
    //
    // Transition ->
    // dp[i][j] = min(skip, pick)
    // where
    // skip = dp[i-1][j]
    // pick = weight[i] + dp[i-1][j-value[i]]   (if j >= value[i])
    //
    // Base Case ->
    // dp[0][0] = 0
    // dp[0][j>0] = INF
    //
    // Final Subproblem ->
    // maximum j such that dp[n][j] <= w

    vector<vector<ll>> dp(n+1, vector<ll>(MAXV+1, INF));
    dp[0][0] = 0;

    for(ll i = 1; i <= n; i++)
    {
        for(ll j = 0; j <= MAXV; j++)
        {
            ll skip = dp[i-1][j];
            ll pick = INF;

            if(j >= value[i] && dp[i-1][j-value[i]] != INF)
                pick = weight[i] + dp[i-1][j-value[i]];

            dp[i][j] = min(skip, pick);
        }
    }

    for(ll j = MAXV; j >= 0; j--)
    {
        if(dp[n][j] <= w)
        {
            cout << j << '\n';
            break;
        }
    }

    return 0;
}
