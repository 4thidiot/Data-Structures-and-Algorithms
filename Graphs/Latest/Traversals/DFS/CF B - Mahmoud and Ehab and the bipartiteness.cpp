#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector <int> edges[N];
vector <bool> visited(N, false);
vector <int> component(N, 0);


void dfs(int curr, int color)
{
    visited[curr] = true;
    component[curr] = color;
    
    for(auto e : edges[curr])
        if(!visited[e])
            dfs(e, 3-color); //// 1 -> 2, 2 -> 1
}

int main() 
{
	int n;
	cin>>n;
	
	for(int i=1; i<n ;i++)
	{
	    int u, v;
	    cin>>u>>v;
	    edges[u].push_back(v);
	    edges[v].push_back(u);
	}

    dfs(1,1);
    
    long long l=0, r=0;
    for(int i = 1; i<=n; i++)
    {
        if(component[i] == 1)
            l++;
        else if(component[i] == 2)
            r++;
    }
    
    cout<<l*r - (n-1)<<'\n';
}
