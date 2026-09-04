#include <bits/stdc++.h>
using namespace std;
#define ll long long

void Dijkstra(int src, vector<vector<pair<int,int>>> &edges, vector <int> &dist)
{
    priority_queue<  pair<int,int>, vector <pair<int,int>>, greater <pair<int,int>>  > pq;
    
    dist[src] = 0;
    pq.push({0, src});
    
    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        
        int currDist = top.first;
        int currNode = top.second;
        
        for(auto e : edges[currNode])
        {
            int nextNode = e.first;
            int edgeWeight = e.second;
            
            if(currDist != dist[currNode])
                continue; //Since we can't pop same node with bigger dist from purrani iteration therefore puraana dist is still present so in order to handle that we have this if statement
            
            if(dist[nextNode] > currDist + edgeWeight)
            {
                dist[nextNode] = currDist + edgeWeight;
                pq.push({dist[nextNode], nextNode});
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
