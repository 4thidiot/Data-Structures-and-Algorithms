#include <bits/stdc++.h>
using namespace std;

// Each number is a graph node and each operation is an edge of cost 1,
// so we reverse the operations and run one BFS from 0 to find the minimum
// operations required for every possible starting number.
// reverse cause 0 is always the starting point and we need starting point to do BFS

const int MOD = 32768;

int main() 
{
	int n;
	cin>>n;
	vector <int> v(n);
	for(auto &it : v)
	    cin>>it;
	
	vector <int> dist(MOD, -1); //Like visited
    queue <int> q;
    
    q.push(0);
    dist[0] = 0;
    
    while(!q.empty())
    {
        int top = q.front();
        q.pop();
        
        int prev = (top - 1 + MOD)%MOD;
        
        if(dist[prev] == -1)
        {
            dist[prev] = dist[top] + 1;
            q.push(prev);
        }
        
        if(top%2 == 0)
        {
            int prev1 = top/2;
            int prev2 = (top+MOD)/2;
            
            if(dist[prev1]==-1)
            {
                dist[prev1] = dist[top] + 1;
                q.push(prev1);
            }
            if(dist[prev2]==-1)
            {
                dist[prev2] = dist[top] + 1;
                q.push(prev2);
            }
        }
    }
    
    for(auto it : v)
        cout<<dist[it]<<" ";
    
    return 0;
}
