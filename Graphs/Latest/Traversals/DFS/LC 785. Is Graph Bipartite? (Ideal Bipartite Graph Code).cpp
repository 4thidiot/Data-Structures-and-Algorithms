class Solution 
{

    bool dfs(int curr, vector <int> &color, vector<vector<int>> &graph)
    {
        for(auto e : graph[curr])
        {
            if(color[e]==-1)
            {
                color[e] = 3 - color[curr];
                if(!dfs(e, color, graph)) 
                    return false;
            }
            if(color[e] == color[curr])
                return false;
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) //Already adjacency list (For 0th index [1,2,3] and so on)
    {
        int n = graph.size();
        vector <int> color(n, -1);
        bool ans;

        for(int i=0; i<n; i++)
        {
            if(color[i]==-1)
            {
                color[i] = 1;
                ans = dfs(i, color, graph);
                if(ans == false)  //since we dont want to continue if we find a single false for a connected component
                    return false;
            }
        }
        return ans;
    }
};
