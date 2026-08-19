#include <bits/stdc++.h>
using namespace std;

const int N = 1e6; //1e8 wont work
vector <pair<int, int>> edges[N];
int cost = 0;
int vis[N]; //Since we will be using undirected list


void dfs(int curr, int parent)
{
    vis[curr] = 1;
    for(auto [e, c] : edges[curr]) //Not curly braces here in auto
        if((!vis[e] || (vis[e] == 1 && e == 1)) && e != parent) // Visit unvisited nodes, allow returning to node 1 to close the ring, but don't go back to the parent
        // Prevents going back to the parent while allowing the final edge to node 1 (e.g. 2→1 blocked, 4→1 allowed)
        {
            cost += c;
            dfs(e, curr);
        }
}


int main() 
{
	int n;
	cin>>n;
	
	int total = 0;
	
	for(int i=0; i<n; i++)
	{
	    int a, b, c;
	    cin>>a>>b>>c;
	    edges[a].push_back({b, 0});
	    edges[b].push_back({a, c});
	    
	    total+=c;
	}
	
	dfs(1, -1);
	
	cout<<min(cost, total-cost)<<'\n';
    
    return 0;
}
