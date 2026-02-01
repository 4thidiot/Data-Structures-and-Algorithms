//* Space optimised DP *//
#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() 
{
    ll n, w;
    cin>>n>>w;
    vector <ll> number(n), weight(n);
    for(ll i=0; i<n; i++)   
        cin>>weight[i]>>number[i];
    //State -> dp[i][j] maximum value/sum that we can get for the prefix of length i such that the allowed capacity/weight is j
    //Transition -> dp[i][j] = max(skip, pick) where skip = dp[i-value][j] and pick dp[i-value][j-weight]
    //Base Case -> dp[0][anything] = 0
    //Final Subproblem -> dp[n][w] since 1 based indexing
    
    vector <ll> prev(w+1, 0); //vector <vector<ll>> dp(n+1, vector <ll> (w+1, 0)); //State and also base case handled here
   
    for(int i=1; i<=n; i++) //from 1 since already base case handled for i=0
    {
        vector <ll> curr(w+1);
        for(int j=0; j<=w; j++)
        {
            ll value = number[i-1];
            ll W = weight[i-1];
            
            ll skip = prev[j];
            ll pick = (j>=W ? (value + prev[j-W]) : 0);
            
            curr[j] = max(pick, skip);
        }
        prev = curr;
    }
    
    cout<<prev[w]<<'\n';
    
    return 0;
}