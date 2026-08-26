#include <bits/stdc++.h>
using namespace std;

const int N=1e3, M=1e3, Q=1e6;
vector <vector<char>> maze(N, vector <char> (M));
vector <pair<int,int>> cells;
vector <vector<bool>> visited(N, vector <bool> (M));
int n, m, k;

void dfs(int x, int y)
{
    visited[x][y] = true;
    cells.push_back({x,y});
    
    if(y + 1 < m && maze[x][y + 1] == '.' && !visited[x][y + 1])
        dfs(x, y + 1);

    if(y - 1 >= 0 && maze[x][y - 1] == '.' && !visited[x][y - 1])
        dfs(x, y - 1);

    if(x + 1 < n && maze[x + 1][y] == '.' && !visited[x + 1][y])
        dfs(x + 1, y);

    if(x - 1 >= 0 && maze[x - 1][y] == '.' && !visited[x - 1][y])
        dfs(x - 1, y);
}

int main() 
{
	cin>>n>>m>>k;
	
	for(int i=0; i<n; i++)
	    for(int j=0; j<m; j++)
	        cin>>maze[i][j];
	
	bool found = false;
	for(int i = 0; i < n && !found; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(maze[i][j] == '.')
            {
                dfs(i, j);
                found = true;
                break;
            }
        }
    }
    
//____________________________-

    for(int i=cells.size()-1; i>=cells.size() - k; i--)
    {
        int x = cells[i].first;
        int y = cells[i].second;
        
        maze[x][y] = 'X';
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout << maze[i][j];
        cout << '\n';
    }
    
    return 0;

}
