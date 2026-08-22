#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int x0,y0,x1,y1;
    cin>>x0>>y0>>x1>>y1;
    
    int n;
    cin>>n;
    
    set <pair<int,int>> allowed;
    
    for(int i=0; i<n; i++)
    {
        int r, a, b;
        cin>>r>>a>>b;
        
        for(int j=a; j<=b; j++)
            allowed.insert({r, j});
    }
    
    queue <pair<pair<int,int>,int>> q;
    
    q.push({{x0, y0}, 0});
    allowed.erase({x0, y0}); //Basically marked visited
    
    while(!q.empty())
    {
        auto top = q.front();
        q.pop();
        
        int x = top.first.first;
        int y = top.first.second;
        int dist = top.second;
        
        if(x==x1 && y==y1)
        {
            cout<<dist<<'\n';
            return 0;
        }
        
        if(allowed.count({x+1, y})) //Down   //basically not 0 basically wo exist karti hai
        {
            q.push({{x+1, y}, dist+1}); 
            allowed.erase({x+1, y});
        }
        if(allowed.count({x-1, y})) //Up
        {
            q.push({{x-1, y}, dist+1}); 
            allowed.erase({x-1, y});
        }
        if(allowed.count({x, y+1})) //Right
        {
            q.push({{x, y+1}, dist+1}); 
            allowed.erase({x, y+1});
        }
        if(allowed.count({x, y-1})) //Left
        {
            q.push({{x, y-1}, dist+1}); 
            allowed.erase({x, y-1});
        }
        if(allowed.count({x-1, y-1})) //Up-Left
        {
            q.push({{x-1, y-1}, dist+1}); 
            allowed.erase({x-1, y-1});
        }
        if(allowed.count({x-1, y+1})) //Up-Right
        {
            q.push({{x-1, y+1}, dist+1}); 
            allowed.erase({x-1, y+1});
        }
        if(allowed.count({x+1, y+1})) //Down-Right
        {
            q.push({{x+1, y+1}, dist+1}); 
            allowed.erase({x+1, y+1});
        }
        if(allowed.count({x+1, y-1})) //Down-Left
        {
            q.push({{x+1, y-1}, dist+1}); 
            allowed.erase({x+1, y-1});
        }
    }
    
    cout<<-1<<'\n';
    
    return 0;
}
