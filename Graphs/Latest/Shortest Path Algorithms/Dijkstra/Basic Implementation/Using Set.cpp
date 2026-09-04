#include <bits/stdc++.h>
using namespace std;
#define ll long long

void Dijkstra(int src, vector<vector<pair<int,int>>> &edges, vector <int> &dist)
{
    set <pair<int, int>> s; //dist, node
    
    dist[src] = 0;
    s.insert({0, src});
    
    while(!s.empty())
    {
        auto top = *s.begin();
        s.erase(top);
        
        int currDist = top.first;
        int currNode = top.second;
        
        for(auto e : edges[currNode]) //iterating through current node's neighbours
        {
            int nextNode = e.first;
            int edgeWeight = e.second;
            
            if(dist[nextNode] > currDist + edgeWeight)
            {
                s.erase({dist[nextNode], nextNode});
                dist[nextNode] = currDist + edgeWeight;
                s.insert({dist[nextNode], nextNode});
            }
        }
    }
}

int main() 
{
	int n, m, src;
	cin>>n>>m>>src;
    
    vector<vector<pair<int,int>>> edges(n);
    
    for(int i=0; i<m; i++)
    {
        int u, v;
        ll w;
        cin>>u>>v>>w;
        edges[u].push_back({v, w});
    }
    
    vector <int> dist(n, INT_MAX);
    Dijkstra(src, edges, dist);
    
    for(int i=0; i<n; i++)
        cout<<i<<": "<<dist[i]<<'\n';
    
    return 0;
}
