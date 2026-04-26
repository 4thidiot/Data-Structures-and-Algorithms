#include <bits/stdc++.h>
using namespace std;
#define ll long long


int generate_subsequence(ll i, ll sum, ll n, vector <ll> arr, ll target)
{
    
    if(i==n)
    {
        if (sum == target)
            return 1;
        return 0; 
    }
    //If sum + arr[i] ko new variable mein save karlete to tab backtracking karni padhti uss variable pe
    ll pick = generate_subsequence(i+1, sum + arr[i], n, arr, target);
    ll skip = generate_subsequence(i+1, sum, n, arr, target);
    
    return pick + skip; //eevry call has its own pick and skip and finally after call stack it returns them to this pick and skip
}


int main() 
{
	ll n, target;
	cin>>n>>target;
	vector <ll> v(n);
	for(auto& it : v)
	    cin>>it;
	
	vector <ll> ans;
    cout<<generate_subsequence(0, 0, n, v, target);
}
