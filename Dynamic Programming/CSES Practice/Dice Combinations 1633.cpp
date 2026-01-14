#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

void solve1(int n)
{
    //state => dp[k] = no of ways to get a sum k from 0
    //transition => dp[k] = sigma(i:1 to 6) dp[k-i]
    //base case => dp[0] = 1 basically no of ways tos get a sum k=0 from 0
    //final subproblem => dp[n] basically no of ways to get a sum k=n from 0
    
    vector <ll> dp(n+1);
    
    dp[0] = 1; //base case
    
    for(ll i=1; i<=n; i++)
        for(ll j=1; j<=6; j++)
            if(j<=i)
                dp[i] = (dp[i] + dp[i-j]) % MOD; //transition
    
    cout<<dp[n]<<'\n'; //final subproblem
}

void solve2(int n)
{
    //state => dp[k] = no of ways to get a sum n such that the curent sum is k
    //transition => sigma(i:1 to 6) dp[k+i]
    //base case => dp[n]=1 basically no of ways to get a sum n such that the current sum is k=n
    //final subproblem => dp[0] basically no of ways to get a sum n such that the current sum is k=0
    
    vector <ll> dp(n+1);
    
    dp[n] = 1; //base case
    
    for(int i = n-1; i>=0; i--) //since rhs needs to calculate first
        for(int j = 1; j<=6; j++)
            if(n-i>=j) //n - i = remaining sum needed to reach n
                dp[i] = (dp[i] + dp[i+j]) % MOD; //transition
    
    cout<<dp[0]<<'\n'; //final subproblem
}

int main() 
{
	ll n;
	cin>>n;
	
	solve2(n);

}
