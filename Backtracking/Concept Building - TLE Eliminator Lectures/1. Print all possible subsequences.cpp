#include <bits/stdc++.h>
using namespace std;
#define ll long long


void generate_subsequence(ll i, ll n, vector <ll> v, vector <ll> &ans)
{
    
    if(i==n)
    {
        for(auto it : ans)
            cout<<it<<" ";
        cout<<endl;
        return;
    }
    
    //Pick
    ans.push_back(v[i]);
    generate_subsequence(i+1, n, v, ans);
    ans.pop_back(); //Back tracking step
    //Skip
    generate_subsequence(i+1, n, v, ans);

}


int main() 
{
	ll n;
	cin>>n;
	vector <ll> v(n);
	for(auto& it : v)
	    cin>>it;
	
	vector <ll> ans;
    generate_subsequence(0, n, v, ans);
}
