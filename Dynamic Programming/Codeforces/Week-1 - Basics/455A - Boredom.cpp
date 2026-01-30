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

    //Make a frequency array first = arr[]
    //State -> dp[i] is the maximum points for index i from 0
    //Transition -> dp[i] = max(dp[i-1] (Skip), dp[i-2] + i*arr[i] (Pick))
    //Base Case -> dp[0] = 0 & dp[1] = arr[1]
    //Final Subproblem -> max(dp)

    vector<ll> arr(100001); //Creating frequency array
    for(auto it : v)
        arr[it]++;

    vector<ll> dp(arr.size(), LLONG_MIN); //State

    dp[0] = 0;
    dp[1] = arr[1]; //Base Case

    for(ll i = 2; i < arr.size(); i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + i * arr[i]); //Transition

    cout << *max_element(dp.begin(), dp.end()); //Final Subproblem

    return 0;
}
