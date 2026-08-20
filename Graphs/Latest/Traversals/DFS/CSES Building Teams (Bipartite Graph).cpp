#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector <int> edges[N];
vector <bool> visited(N, false);
vector <int> component(N, 0);
int cnt = 0;
vector<int> color(N, 0);


void dfs(int curr, int p)
{
    visited[curr] = true;
    component[curr] = cnt;
    
    for(auto e : edges[curr])
    {
        // if(e==p)
        //     continue;
        if(!visited[e])
        {
            color[e] = 3 - color[curr]; // 1 -> 2, 2 -> 1
            dfs(e, curr);
        }
        // else
        // {
        //     cout << "IMPOSSIBLE\n";
        //     exit(0);
        // }
        //Don't treat it as cycle mean IMPOSSIBLE because it still can be bipartite
        
        else if(color[e]==color[curr])
        {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
    }
}

int main() 
{
	int n, m;
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
	    int u, v;
	    cin>>u>>v;
	    edges[u].push_back(v);
	    edges[v].push_back(u);
	}
	
	for(int i=1; i<=n; i++)
	{
	    if(!visited[i])
	    {
	        color[i] = 1;  // starting color of each component
	        dfs(i, -1);
	        cnt++;
	    }
	}
	
	
	
	for(int i = 1; i <= n; i++)
    cout << color[i] << " ";
    
	//---------------------------------------

    // for(int i=1; i<=n; i++)
    //     cout<<component[i]<<" ";
        
    //---------------------------------------
    // int f1=0, f2=0;
    // for(int i=1; i<=n; i++)
    // {
    //     if(component[i]==0)
    //     {
    //         if(f1==0)
    //         {
    //             cout<<1<<" ";
    //             f1=1;
    //         }
    //         else
    //         {
    //             cout<<2<<" ";
    //             f1=0;
    //         }
    //     }
    //     else
    //     {
    //         if(f2==0)
    //         {
    //             cout<<1<<" ";
    //             f2=1;
    //         }
    //         else
    //         {
    //             cout<<2<<" ";
    //             f2=0;
    //         }
    //     }
    // }
	
	return 0;
}
