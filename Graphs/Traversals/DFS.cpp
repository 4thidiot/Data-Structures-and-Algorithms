#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector <int> AdjList[], vector <int> &visited, vector <int> &ans)
{
    visited[node] = 1;
    ans.push_back(node);
    
    for(int j=0; j<AdjList[node].size(); j++)
    {
        if(visited[AdjList[node][j]]==0)
            dfs(AdjList[node][j], AdjList, visited, ans);
    }
}


int main() 
{
    //creating AdjList
	int vertex, edges;
	cin>>vertex>>edges;
	
	vector <int> AdjList[vertex];
	
	for(int i=0; i<edges; i++)
	{
	    int u, v;
	    cin>>u>>v;
	    AdjList[u].push_back(v);
	    AdjList[v].push_back(u);
	}
	//dfs
	vector <int> visited(edges, 0);
	vector <int> ans;
	int node = 0;
    
    dfs(node, AdjList, visited, ans);
    
    //printing the dfs answer
    for(auto it : ans)
        cout<<it<<" ";
        
    return 0;
}


//INPUT: for the graph in my copy
// 8 16
// 0 1
// 0 3
// 0 2
// 1 7
// 1 4
// 4 5
// 5 6
// 5 2
