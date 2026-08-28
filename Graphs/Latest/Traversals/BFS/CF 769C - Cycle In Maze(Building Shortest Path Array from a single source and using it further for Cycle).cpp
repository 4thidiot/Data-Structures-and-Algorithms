#include <bits/stdc++.h>
using namespace std;

//Goal - Using BFS finding the shortest path to each node (Because utna hi waapas aane mein lagega (Lexicographically) and then using the loop condition is returnable)

int main() 
{
	int n, m, k;
	cin>>n>>m>>k;
	
	if(k%2 != 0)
	{
	    cout<<"IMPOSSIBLE\n";
	    exit(0);
	}
	
	vector<vector<char>> maze(n, vector<char> (m));
	vector<vector<int>> dist(n, vector<int> (m, -1)); //Instead of visited
	
	pair <int, int> start;
	
	for(int i=0; i<n; i++)
	    for(int j=0; j<m; j++)
	    {
	        cin>>maze[i][j];
	        if(maze[i][j] == 'X')
	        {
	            start.first = i;
	            start.second = j;
	        }
	    }
    
    //Constructing the shortest distance from X to each node array (dist array)
    queue <pair<int,int>> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    
    while(!q.empty())
    {
        auto top = q.front();
        int x = top.first, y = top.second;
        q.pop();
        
        if(x+1<n && maze[x+1][y]!='*' && dist[x+1][y]==-1) //D
        {
            dist[x+1][y] = 1 + dist[x][y];
            q.push({x+1,y});
        }
        if(y-1>=0 && maze[x][y-1]!='*' && dist[x][y-1]==-1) //L
        {
            dist[x][y-1] = 1 + dist[x][y];
            q.push({x,y-1});
        }
        if(y+1<m && maze[x][y+1]!='*' && dist[x][y+1]==-1) //R
        {
            dist[x][y+1] = 1 + dist[x][y];
            q.push({x,y+1});
        }
        if(x-1>=0 && maze[x-1][y]!='*' && dist[x-1][y]==-1) //U
        {
            dist[x-1][y] = 1 + dist[x][y];
            q.push({x-1,y});
        }
    }
    
    //Now building the Answer array using the loop condition of returning using the dist array
    string ans = "";
    
    int x = start.first;
    int y = start.second;
    
    for(int steps=0; steps<k; steps++)
    {
        int remaining = k - steps - 1;
        
        if(x+1<n && maze[x+1][y]!='*' && dist[x+1][y]<=remaining) //D
        {
            ans += 'D';
            x++;
        }
        else if(y-1>=0 && maze[x][y-1]!='*' && dist[x][y-1]<=remaining) //L
        {
            ans += 'L';
            y--;
        }
        else if(y+1<m && maze[x][y+1]!='*' && dist[x][y+1]<=remaining) //R
        {
            ans += 'R';
            y++;
        }
        else if(x-1>=0 && maze[x-1][y]!='*' && dist[x-1][y]<=remaining) //U
        {
            ans += 'U';
            x--;
        }
        else
        {
            cout<<"IMPOSSIBLE\n";
            exit(0);
        }
    }
    
    cout<<ans<<'\n';
    
    return 0;
}
