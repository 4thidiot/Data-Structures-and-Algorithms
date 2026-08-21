#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n;
	cin>>n;
	
	vector <int> edges[n];
	vector <bool> visited(n, false);
	
	for(int i=0; i<n-1; i++)
	{
	    int u, v;
	    cin>>u>>v;
	    edges[u].push_back(v);
	    edges[v].push_back(u);
	}
	
	queue <int> q;
	
	q.push(0);
	visited[0] = true;
	
	
	while(!q.empty())
	{
	    int top = q.front();
	    q.pop();
	    
	    cout<<top<<" ";
	    	
	    for(auto e : edges[top])
	        if(!visited[e])
	        {
	            visited[e] = true;
	            q.push(e);
	        }
	}

}
