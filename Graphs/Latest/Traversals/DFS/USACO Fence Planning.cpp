#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
vector <int> edges[N];
vector <bool> visited(N, false);
map <int, pair <int,int>> mp;
int mnx=1e9,mny=1e9,mxx=0,mxy=0;



void dfs(int cow)
{
    visited[cow] = true;

    mnx = min(mnx, mp[cow].first);
    mxx = max(mxx, mp[cow].first);
    mny = min(mny, mp[cow].second);
    mxy = max(mxy, mp[cow].second);

    for(int e : edges[cow])
    {
        if(!visited[e])
            dfs(e);
    }
}


int main() 
{
    
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    
    int n, m;
    cin>>n>>m;
    
    for(int cow=0; cow<n; cow++)
    {
        int u, v;
        cin>>u>>v;
        mp[cow+1] = make_pair(u, v);
    }
    
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    
    int res=1e9;
    for(int i=1; i<=n; i++)
    {
        mnx=1e9,mny=1e9,mxx=0,mxy=0; //This gets executed for a new component
        if(!visited[i])
        {
            dfs(i);
            res=min(res,2*(mxx-mnx)+2*(mxy-mny));
        }
    }
    cout<<res<<'\n';
    
    return 0;
}
