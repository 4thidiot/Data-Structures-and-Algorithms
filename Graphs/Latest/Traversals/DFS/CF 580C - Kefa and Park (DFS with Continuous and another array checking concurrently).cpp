#include <bits/stdc++.h>
using namespace std;


void dfs(int curr, int cats, int m, vector <vector<int>> &edges, vector <bool> &visited, vector <int> &cat, int &ans) 
{
    visited[curr] = true;
    
    
    if(cat[curr]==1)
        cats++;
    else
        cats = 0; //Since continuous nodes condition
    
    if(cats > m)
        return;
    
    
    bool leaf = true;
     
    for(auto e : edges[curr])
    {
        if(!visited[e])
        {
            leaf = false; //If we find an unvisited neighbour, that means the               current node has a child
            dfs(e, cats, m, edges, visited, cat, ans);
        }
    }
    
    if(leaf)
        ans++;
}


int main() 
{
	int n, m; //m isnt the number of edges here rather it is the number of cats also number of edges is vertices-1 (n-1)
	cin>>n>>m;
	
	vector <int> cat(n+1, 0);
	for(int i=1; i<=n; i++)
	    cin>>cat[i];
	    
	vector <vector<int>> edges(n+1, vector <int> ());
	
	for(int i=1; i<n; i++)
	{
	    int u, v;
	    cin>>u>>v;
	    edges[u].push_back(v);
	    edges[v].push_back(u);
	}
	
	vector <bool> visited(n+1, false);
	int ans = 0;
	
	dfs(1, 0, m, edges, visited, cat, ans);
    
    cout << ans;
}
