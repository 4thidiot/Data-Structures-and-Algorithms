//*Space Optimised Version*//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main() 
{
	//State -> dp[i][j] = number of ways going from (i,j) to (n-1, n-1)
	//Base Case -> dp[n-1][n-1] = 0 (basically nextRow[n-1] = 0)               if (arr[n-1][n-1]=='*') nextRow[i] = 0; else nextRow[n-1] = 1;
	//Transition -> if arr[i][j] == '*' then dp[i][j] = 0 basically currentRow[j]=0;
	//              else ans1 = dp[i+1][j]; basically nextRow[j]
	//                   ans2 = dp[i][j+1]; basically currentRow[j+1]
	//                   currentRow[j] = (ans1 + ans2)%MOD
    //Final Subproblem -> dp[0][0] basically nextRow[0]
    
    ll n;
    cin>>n;
    string arr[n];
    for(int i=0; i<n; i++)
            cin>>arr[i]; //takes input of entire row at once!
            
    vector <int> nextRow(n); //State
    
    //Base Case
    if(arr[n-1][n-1] == '*')
        nextRow[n-1] = 0;
    else
        nextRow[n-1] = 1;
    
    //Creating the nextRow basically filling the last Row first
    for(int i=n-2; i>=0; i--)
    {
        if(arr[n-1][i] =='*')
            nextRow[i] = 0;
        else
            nextRow[i] = nextRow[i+1];
    }
    //Transition
    for(int i=n-2; i>=0; i--)
    {
        vector <int> currentRow(n);
        for(int j=n-1; j>=0; j--)
        {
            if(i==n-1 && j==n-1)
                continue; //Handled in base case could have done that here too
            else if(arr[i][j] == '*')
                currentRow[j] = 0;
            else
            {
                int ans1 = (i<n-1 ? nextRow[j] : 0); //tabhi can go down
                int ans2 = (j<n-1 ? currentRow[j+1] : 0); //tabhi can go right
                currentRow[j] = (ans1 + ans2) % MOD;
            }
        }
        nextRow = currentRow;
    }
    
    cout<<nextRow[0]<<'\n'; //Final Subproblem
}
