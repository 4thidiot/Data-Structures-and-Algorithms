//Same concept as surrounding regions LC question
class Solution {

    void dfs(int x, int y, vector<vector<bool>> &visited, vector<vector<int>> &grid, int dx[], int dy[], int n, int m)
    {
        visited[x][y] = true;
        for(int i=0; i<4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx>=0 && ny>=0 && nx<n && ny<m && !visited[nx][ny] && grid[nx][ny]==1)
            {
                visited[nx][ny] = true;
                grid[nx][ny] = 2;
                dfs(nx, ny, visited, grid, dx, dy, n, m);
            }
        }    
    }

public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++)
        {
            if(grid[i][0]==1)
                grid[i][0] = 2;
            if(grid[i][m-1]==1)
                grid[i][m-1] = 2;
        }
        for(int i=0; i<m; i++)
        {
            if(grid[0][i]==1)
                grid[0][i] = 2;
            if(grid[n-1][i]==1)
                grid[n-1][i] = 2;
        }

        vector<vector<bool>> visited(n, vector<bool> (m, false));
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==2 && !visited[i][j])
                    dfs(i, j, visited, grid, dx, dy, n, m);
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                    ans++;
            }
        }
        return ans;
    }
};
