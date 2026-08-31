class Solution 
{
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>> visited(n, vector <bool> (m, false));
        queue <pair<int,int>> q;
        int original = image[sr][sc];

        q.push({sr, sc});
        visited[sr][sc] = true;
        image[sr][sc] = color;

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
                if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny] && image[nx][ny]==original)
                {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    image[nx][ny] = color;
                }
            }
        }
        return image;
    }
};
