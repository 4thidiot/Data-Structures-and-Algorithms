#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main() 
{
	//State -> dp[i][j] = number of ways going from (i,j) to (n-1, n-1)
	//Base Case -> dp[n-1][n-1] = 0 if (arr[n-1][n-1]=='*') else arr[n-1][n-1]=1
	//Transition -> if arr[i][j] == '*' then dp[i][j] = 0;
	//              else ans1 = dp[i+1][j]; 
	//                   ans2 = dp[i][j+1];
	//                   dp[i][j] = (ans1 + ans2)%MOD
    //Final Subproblem -> dp[0][0]
    
    ll n;
    cin>>n;
    string arr[n];
    for(int i=0; i<n; i++)
            cin>>arr[i]; //takes input of entire row at once!
            
    vector <vector<int>> dp(n, vector <int> (n)); //State
    
    //Base Case
    if(arr[n-1][n-1] == '*')
        dp[n-1][n-1] = 0;
    else
        dp[n-1][n-1] = 1;
        
    //Transition
    for(int i=n-1; i>=0; i--)
    {
        for(int j=n-1; j>=0; j--)
        {
            if(i==n-1 && j==n-1)
                continue; //Handled in base case could have done that here too
            else if(arr[i][j] == '*')
                dp[i][j] = 0;
            else
            {
                int ans1 = (i<n-1 ? dp[i+1][j] : 0); //tabhi can go down
                int ans2 = (j<n-1 ? dp[i][j+1] : 0); //tabhi can go right
                dp[i][j] = (ans1 + ans2) % MOD;
            }
        }
    }
    
    cout<<dp[0][0]<<'\n'; //Final Subproblem
}
