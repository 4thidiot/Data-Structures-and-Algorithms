class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> visited(n, vector <bool> (m, false));
        vector<vector<int>> ans(n, vector <int> (m, 0));
        queue <pair<int,int>> q;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    visited[i][j] = true;
                    ans[i][j] = 0;
                }
            }
        }

        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            int x = top.first;
            int y = top.second;

            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};

            for(int i=0; i<4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m && mat[nx][ny]==1 && !visited[nx][ny])
                {
                    visited[nx][ny] = true;
                    ans[nx][ny] = ans[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return ans;
    }
};
