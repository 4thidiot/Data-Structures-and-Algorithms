#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector <pair<int,int>> edges[N];
int vis[N];
int Maxcost = 0;


void dfs(int curr, int cost)
{
    vis[curr] = 1;
    
    Maxcost = max(Maxcost, cost);
    
    for(auto [e, c] : edges[curr])
        if(!vis[e])
        {
            dfs(e, cost+c);
        }
}

int main() 
{
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
	    int u, v, c;
	    cin>>u>>v>>c;
	    edges[u].push_back({v, c});
	    edges[v].push_back({u, c});
	}
	
	dfs(0, 0);
	
    cout<<Maxcost<<'\n';
    
    return 0;
}
