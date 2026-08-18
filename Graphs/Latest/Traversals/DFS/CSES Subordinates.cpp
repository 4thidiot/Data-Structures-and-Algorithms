#include <bits/stdc++.h>
using namespace std;


void dfs(int s, vector <vector<int>> &adj, vector <int> &child)
{
    for(auto kid : adj[s])
    {
        dfs(kid, adj, child);
        child[s] += child[kid] + 1;
    }
}

int main() 
{
	int n;
	cin>>n;
// 	vector<int> v(n);
// 	for(auto &it:v)
// 	    cin>>it;
	
// 	map <int, int> m;     //Won't work since it is a tree dfs question just count the child nodes of each node but I will treat it as a graph and just solve it
	
// 	for(auto it : v)
// 	    m[it]++;
	
// 	cout<<n-1<<" ";
// 	for(int i=2; i<=n; i++)
// 	    cout<<m[i]<<" ";
    

    vector <vector<int>> adj(n+1, vector <int> ()); //array of bosses and it stores their child
    vector <int> child(n+1, 0);
    
    for(int i=2; i<=n; i++)
    {
        int a;
        cin>>a;
        adj[a].push_back(i); //Basically v[x] -> to whose boss they are
    }
    
    dfs(1, adj, child); //No need for visited array since this is a directed graph
    
    for(int i=1; i<=n; i++)
        cout<<child[i]<<" ";

}
