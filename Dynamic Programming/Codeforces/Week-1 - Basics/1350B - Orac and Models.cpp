#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

void solve()
{
    ll n;
    cin >> n;
    vector <ll> s(n+1);
    for(int i=1; i<=n; i++)
        cin>>s[i];
    
    // state -> dp[k] = maximum sequence ending at k
    // transition -> dp[k] = max(dp[k], dp[i] + 1) where j is from 2*i, 3*i and so on
    // base case -> dp[1] = 1
    // final subproblem -> dp[n]
    
    vector <int> dp(n+1, 1);
    
    dp[1] = 1; //base condition
    
    for(int i=1; i<=n; i++)
        for(int j=2*i; j<=n; j+=i) //sieve of eratosthenes
            if(s[j] > s[i])
                dp[j] = max(dp[j], dp[i]+1); //update needed if current+1 warna memorised value hi badi hai can be also true
            
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() 
{
	int t;
	cin>>t;
	
	while(t--)
	    solve();

}
