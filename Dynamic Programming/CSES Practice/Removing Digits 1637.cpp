#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin>>n;
    
    // state -> dp[k] -> min steps to convert k to 0
    // transition -> dp[k] = min(dp[n-di] + 1) where di are the digits & +1 because 1 step already taken to reduce this number n by acertain digit
    // base case -> dp[0] = 0
    // final subproblem -> dp[n]
    
    vector <ll> dp(n+1, INT_MAX); //state
    
    dp[0] = 0; //base case
    
    for(int i=1; i<=n; i++)
    {
        string a = to_string(i); //converts the number to string
        for(char c: a)
        {
            int digit = c - '0';
            if(digit!=0)
                dp[i] = min(dp[i], dp[i - digit]+1); //transition
        }
    }
    
    cout << dp[n] << '\n';
}

int main() 
{
	ll t=1;
// 	cin>>t;
	while(t--)
	    solve();

}
