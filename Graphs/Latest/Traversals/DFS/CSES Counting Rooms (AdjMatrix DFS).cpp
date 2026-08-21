#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<vector<char>> adj(N,vector<char>(N));
vector <vector<bool>> visited(N, vector <bool> (N, false));
int ans = 0;
int n, m;


void dfs(int i, int j)
{
    visited[i][j] = true;

    if(i + 1 < n && adj[i + 1][j] == '.' && !visited[i + 1][j]) //Going right
        dfs(i + 1, j);

    if(j + 1 < m && adj[i][j + 1] == '.' && !visited[i][j + 1]) //Going up
        dfs(i, j + 1);

    if(i - 1 >= 0 && adj[i - 1][j] == '.' && !visited[i - 1][j]) //Going left
        dfs(i - 1, j);

    if(j - 1 >= 0 && adj[i][j - 1] == '.' && !visited[i][j - 1]) //GOing down
        dfs(i, j - 1);
}

int main() 
{
	cin>>n>>m;
	
	for(int i=0; i<n; i++)
	    for(int j=0; j<m; j++)
	    {
	        char a;
	        cin>>a;
	        adj[i][j] = a;
	    }
	
	for(int i=0; i<n; i++)
	    for(int j=0; j<m; j++)
	    {
	        if(!visited[i][j] && adj[i][j]=='.')
	        {
	            dfs(i, j);
	            ans++;
	        }
	    }
	    
	cout<<ans<<'\n';
    
    return 0;
}
