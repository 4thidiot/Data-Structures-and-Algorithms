//Push all sources in queue initially and then while ke andar waala while for q.size() uss samay ka (level by level hoga)
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int n;
	cin>>n;
	
	int dx[] = {1, 1, -1, -1, -2, -2, 2, 2};
    int dy[] = {-2, 2, -2, 2, -1, 1, -1, 1};
    
    vector <vector<int>> board(n, vector <int> (n, -1));
    
    queue <pair<int, int>> q;
    
    q.push({0,0});
    board[0][0] = 0;
    
    while(!q.empty())
    {
        auto top = q.front();
        q.pop();
        
        int x = top.first;
        int y = top.second;
        
        for(int i=0; i<8; i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if(nx>=0 && nx<n && ny>=0 && ny<n && board[nx][ny]==-1)
            {
                board[nx][ny] = board[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<board[i][j]<<" ";
        cout<<'\n';
    }
    
    return 0;
}
