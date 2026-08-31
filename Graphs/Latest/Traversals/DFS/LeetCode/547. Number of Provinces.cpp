class Solution 
{
    void dfs(int curr, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        visited[curr] = true;
        for(int e=0; e<isConnected.size(); e++) //Since adj matrix and not list so no auto e : isConnected[curr]
        {
            if(isConnected[curr][e]==1 && !visited[e])
            {
                visited[e] = true;
                dfs(e, isConnected, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int ans=0;
        vector<bool> visited(isConnected.size(), false);
        for(int i=0; i<isConnected.size(); i++)
        {
            if(!visited[i])
            {
                dfs(i, isConnected, visited);
                ans++;
            }
        }
        return ans;
    }
};

