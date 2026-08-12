#include <bits/stdc++.h>
using namespace std;

void dfs(int curr, vector <vector<int>> &edges, vector <bool> &visited)
{
    visited[curr] = true;
    cout<<curr<<" ";
    
    for(int e : edges[curr])
        if(!visited[e])
            dfs(e, edges, visited);
}

int main() 
{
	int n, m; //n matlab only vertex and m hai ki kitni lines input leni hai
	cin>>n>>m;
	vector <vector<int>> edges (n, vector <int> ()); 
	
	for(int i=0; i<m; i++)
	{
	    int u, v; 
	    cin>>u>>v;
	    edges[u].push_back(v);
	    edges[v].push_back(u);
	}
	
	vector <bool> visited(n, false);
	dfs(0, edges, visited);
}
 
//  0-1-2  3-4
//       |____|

// For Input:
// 5 5
// 0 1
// 1 2
// 3 4
// 4 2
          
