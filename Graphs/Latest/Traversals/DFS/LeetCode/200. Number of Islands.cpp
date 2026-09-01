class Solution 
{
    void dfs(int x, int y, vector<vector<bool>> &visited, vector<vector<char>> &grid, int n, int m, int dx[], int dy[])
    {
        visited[x][y] = true;
        for(int i=0; i<4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && grid[nx][ny]=='1')
                dfs(nx, ny, visited, grid, n, m, dx, dy);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        vector<vector<bool>> visited(n, vector <bool> (m, false));
        int dx[] = {0,0,-1,1};
        int dy[] = {1,-1,0,0};

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    dfs(i, j, visited, grid, n, m, dx, dy);
                    ans++;
                }
            }
        }
        return ans;
    }
};
