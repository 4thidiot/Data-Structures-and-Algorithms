#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Intuition: 
//     Since at each step there are 2 steps possible so becomes a tree and at each we need to find the path to the leaf node which matches with b, so we use dfs

void dfs(ll a, ll b, vector <ll> &path)
{
    if(a>b)
        return;
    
    path.push_back(a);
        
    if(a==b)
    {
        cout<<"YES\n";
        cout<<path.size()<<'\n';
        for(auto it : path)
            cout<<it<<" ";
        exit(0); //Program terminated successfully (0 for successfully and 1 for failure typically)
    }
    
    dfs(a*2, b, path);
    dfs(10*a+1, b, path);
    
    path.pop_back(); //Typical backtracking
}


int main() 
{
	ll a, b;
	cin>>a>>b;
	
	vector <ll> path;
	
	dfs(a, b, path);
	
    cout<<"NO\n";
}
