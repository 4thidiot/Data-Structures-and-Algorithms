#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int vertex, edges;
	cin>>vertex>>edges;
	
	vector <int> AdjList[vertex];
	
	for(int i=0; i<edges; i++)  //creating AdjList
	{
	    int u, v;
	    cin>>u>>v;
	    AdjList[u].push_back(v);
	    AdjList[v].push_back(u);
	}
	
    
    //BFS
    queue <int> q;
    vector <int> visited (vertex, 0);
    vector <int> answer;
    
    q.push(0);
    visited[0]=1;
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        answer.push_back(node);
        
        for(int j=0; j<AdjList[node].size(); j++)
        {
            if(!visited[AdjList[node][j]])
            {
                visited[AdjList[node][j]] = 1;
                q.push(AdjList[node][j]);
            }
        }
    }
	
	for(auto it : answer)
	    cout<<it<<" ";
	
	
}
