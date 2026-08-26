#include <bits/stdc++.h>
using namespace std;

const int N = 1e3, M = 1e3;

vector<vector<char>> maze(N, vector<char>(M));
vector<vector<bool>> visited(N, vector<bool>(M));

int n, m, k;

int main()
{
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> maze[i][j];

    queue<pair<int, int>> q;
    vector<pair<int, int>> cells;

    bool found = false;

    for(int i = 0; i < n && !found; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(maze[i][j] == '.')
            {
                q.push({i, j});
                visited[i][j] = true;
                found = true;
                break;
            }
        }
    }

    while(!q.empty())
    {
        auto top = q.front();
        q.pop();

        int i = top.first;
        int j = top.second;

        cells.push_back({i, j});

        if(i + 1 < n && maze[i + 1][j] == '.' && !visited[i + 1][j])
        {
            q.push({i + 1, j});
            visited[i + 1][j] = true;
        }

        if(i - 1 >= 0 && maze[i - 1][j] == '.' && !visited[i - 1][j])
        {
            q.push({i - 1, j});
            visited[i - 1][j] = true;
        }

        if(j + 1 < m && maze[i][j + 1] == '.' && !visited[i][j + 1])
        {
            q.push({i, j + 1});
            visited[i][j + 1] = true;
        }

        if(j - 1 >= 0 && maze[i][j - 1] == '.' && !visited[i][j - 1])
        {
            q.push({i, j - 1});
            visited[i][j - 1] = true;
        }
    }

    for(int i = cells.size() - 1; i >= (int)cells.size() - k; i--)
    {
        int x = cells[i].first;
        int y = cells[i].second;

        maze[x][y] = 'X';
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << maze[i][j];

        cout << '\n';
    }

    return 0;
}
