// Earlier, I directly pushed every move made during BFS into ans. This was wrong because BFS explores multiple branches, so ans stored moves from all explored cells, including wrong branches, instead of one path from A to B. Now, I store the direction used to reach each cell and backtrack from B to A to reconstruct only the correct shortest path.
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n, m;
	cin>>n>>m;
	
	vector<vector<char>> maze(n, vector <char> (m));
	vector<vector<bool>> visited(n, vector <bool> (m, false));
	vector <char> ans;
	vector<vector<char>> parent(n, vector<char>(m));
	
	pair <int,int> start, end;
	for(int i=0; i<n; i++)
	    for(int j=0; j<m; j++)
	    {
	        cin>>maze[i][j];
	        if(maze[i][j]=='A')
	            start = {i, j};
	        if(maze[i][j]=='B')
	            end = {i, j};
	    }
	
	queue <pair<int,int>> q;
	
	q.push(start);
	visited[start.first][start.second] = true;
	int flag=0;
	
	while(!q.empty())
	{
	    auto top = q.front();
	    q.pop();
	    
	    int i = top.first;
	    int j = top.second;
	    
	    if(top == end)
	    {    
	        flag=1;
	        break;
	    }
	    if(i+1 < n && maze[i+1][j]!='#' && !visited[i+1][j])
	    {
	        visited[i+1][j] = true;
	        q.push({i+1, j});
	        parent[i + 1][j] = 'D';
	    }
	    if(j+1 < m && maze[i][j+1]!='#' && !visited[i][j+1])
	    {
	        visited[i][j+1] = true;
	        q.push({i, j+1});
	        parent[i][j + 1] = 'R';
	    }
	    if(i-1 >= 0 && maze[i-1][j]!='#' && !visited[i-1][j])
	    {
	        visited[i-1][j] = true;
	        q.push({i-1, j});
	        parent[i - 1][j] = 'U';
	    }
	    if(j-1 >= 0 && maze[i][j-1]!='#' && !visited[i][j-1])
	    {
	        visited[i][j-1] = true;
	        q.push({i, j-1});
	        parent[i][j - 1] = 'L';
	    }
	}
	
	if(flag==0)
	    cout<<"NO\n";
	
	else
	{
	    int x = end.first;
        int y = end.second;
        
        while(make_pair(x, y) != start) //Backtracking
        {
            char c = parent[x][y];
            ans.push_back(c);
            
            if(c == 'D')
                x--;
            else if(c == 'U')
                x++;
            else if(c == 'R')
                y--;
            else
                y++;
        }
        reverse(ans.begin(), ans.end());
        
        cout << "YES\n";
        cout << ans.size() << '\n';
        
        for(auto it : ans)
            cout << it;
	}
	
    return 0;
}
