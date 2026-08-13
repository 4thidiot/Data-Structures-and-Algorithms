#include <bits/stdc++.h>
using namespace std;

//Basically finding connected components kind of a question

void dfs(int curr, vector <vector<int>> &edges, vector <bool> &visited, vector <int> &connected, int &count)
{
    visited[curr] = true;
    connected[curr] = count;
    
    for(int e : edges[curr])
        if(!visited[e])
        {
            dfs(e, edges, visited, connected, count);
            count++;
        }
}

int main()
{
	int n, m;
	cin>>n>>m;
	
	vector <vector<int>> edges(n+1, vector <int> ());
	
	for(int i=0; i<m; i++)
	{
	    int u, v;
	    cin>>u>>v;
	    edges[u].push_back(v);
	    edges[v].push_back(u);
	}
	
	
	vector <bool> visited(n+1, false);
	vector <int> connected(n+1, 0);
	int count = 0;
	
    for(int i=1; i<=n; i++)
        if(!visited[i])
            dfs(i, edges, visited, connected, count);
            
    // _______________________________________________________
        
    cout<<count-1<<'\n';
    
    for(int i=1; i<n; i++)
    {
        if(connected[i] != connected[i+1])
        {
            cout<<i<<" "<<i+1<<" ";
        }
    }
    
}
