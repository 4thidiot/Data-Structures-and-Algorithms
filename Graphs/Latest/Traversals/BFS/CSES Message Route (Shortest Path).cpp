#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n, m;
	cin>>n>>m;
	
	vector <int> edges[n+1];
	vector <bool> visited(n+1, false);
	
	for(int i=0; i<m; i++)
	{
	    int u, v;
	    cin>>u>>v;
	    edges[u].push_back(v);
	    edges[v].push_back(u);
	}
    
    vector <int> parent(n+1, -1);
    queue <int> q;
    
    q.push(1);
    visited[1] = true;
    
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        
        for(int e : edges[top])
            if(!visited[e])
            {
                visited[e] = true;
                q.push(e);
                parent[e] = top;
            }
    }
    
    //Just printing now using backtracking like path finding
    if(!visited[n])
        cout<<"IMPOSSIBLE\n";
    else
    {
        vector <int> path;
        int curr = n;
        
        while(curr!=-1)
        {
            path.push_back(curr);
            curr = parent[curr];
        }
        
        reverse(path.begin(), path.end());
        
        cout<<path.size()<<'\n';
        for(auto it : path)
            cout<<it<<" ";
    }
    
    return 0;
}
