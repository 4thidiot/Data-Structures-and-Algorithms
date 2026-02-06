#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Project
{
    ll s, e, r;
};

int main() 
{
	ll n;
	cin>>n;
    
    vector <Project> v(n+1);
    for(int i=1; i<=n; i++)
        cin>>v[i].s>>v[i].e>>v[i].r;
    
    //Sorting Projects by ending time
    sort(v.begin(), v.end(), [&](auto a, auto b)
    {
        return a.e < b.e; //Custom comparator even opp works obviously...
    });
    
    vector<ll> dp(n+1, 0); //State
    vector<ll> end(n+1); //Creating this seperately cause upper_bound wont work on struct array directly

    for(int i = 1; i <= n; i++)
        end[i] = v[i].e;
        
    //State -> dp[i] = maximum reward achievable using the first i projects (sorted based on end time)
    //Transition -> For the i-th project:
    //   1) Skip the project:
    //      dp[i] = dp[i-1]

    //   2) Take the project: This gives us the first index where end > start[i]-1
    //      dp[i] = reward[i] + dp[j]
    //      where j is the largest index < i such that
    //      end[j] < start[i]
    
    //Base Case -> dp[0] = 0 since no projects means no reward
    //Final Subproblem -> dp[n]
    
    for(int i=1; i<=n; i++) //Transition
    {
        //Option-1: skip current project
        dp[i] = dp[i-1];
        //Option-2: Find last non-overlapping project using binary search
        int j = upper_bound(end.begin()+1, end.begin()+i, v[i].s - 1) - end.begin() - 1; //-end.begin( cause returns the iterator so it converts to index) and -1 cause upperbound returns the first index greater than it but we need the the last which is just smaller
        dp[i] = max(dp[i], v[i].r + dp[j]);
    }
    cout<<dp[n]; //Final Subproblem
}
