//Iterate over the boundary of the grid and turn all 0s to # then normal dfs tp turn 0s to X which are connected and then flip # to 0s again since on boundary

class Solution {

    void dfs(int x, int y, vector<vector<bool>> &visited, vector<vector<char>> &board, int dx[], int dy[], int n, int m)
    {
        visited[x][y] = true;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m
            && !visited[nx][ny] && board[nx][ny]=='O')
            {
                visited[nx][ny] = true;
                board[nx][ny] = '#';   // CHANGE: X -> #
                dfs(nx, ny, visited, board, dx, dy, n, m);
            }    
        }
    }

public:
    void solve(vector<vector<char>>& board) 
    {
        int n = board.size();
        int m = board[0].size();
        
        //Iterating on the boundary
        for(int i=0; i<n; i++)
        {
            if(board[i][0]=='O')
                board[i][0] = '#';
            if(board[i][m-1]=='O')
                board[i][m-1] = '#';
        }
        for(int i=0; i<m; i++)
        {
            if(board[0][i]=='O')
                board[0][i] = '#';
            if(board[n-1][i]=='O')
                board[n-1][i] = '#';
        }

        //Now normal dfs for connected components with changing
        vector<vector<bool>> visited(n, vector <bool> (m, false));
            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};

        //If you start DFS from an arbitrary O, you don't know whether that region is safe or surrounded.
        //That's why DFS starts from the boundary, not from arbitrary Os. isliye changing board[i][j]=='O' to == '#'
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j] && board[i][j]=='#')
                    dfs(i, j, visited, board, dx, dy, n, m);
            }
        }

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(board[i][j]=='#') //because inpe ham boundary se pahuch gaye therefore ye to enclosed hi nahi hai
                    board[i][j]='O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X'; //Those are exactly the Os that are surrounded and need to become X
    }
};
