#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() 
{
	ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &it : v)
        cin >> it;
        
    //State -> dp[i] is the length of increasing subarray ending at i
    //Transition -> if(v[i] > v[i-1] : dp[i] = dp[i-1] + 1) 
    //              else: dp[i] = i
    //Base Case -> dp[0] = 1
    //Final Subproblem -> max(dp)
    
    vector <int> dp(n); //State
    
    dp[0] = 1; //Base Case
    
    for(int i=1; i<n; i++)
    {
        if(v[i] > v[i-1])
            dp[i] += dp[i-1] + 1;
        else
            dp[i] = 1;
    }
    
    cout << *max_element(dp.begin(), dp.end());
}
