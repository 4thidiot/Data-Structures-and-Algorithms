#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() 
{
	ll N;
	cin>>N;
	
	vector<vector<int>> a(N, vector<int>(3)); //2D Vector where first index is the day and second index is again a 2d vector storing the value of that day
    for (int i = 0; i < N; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2]; 
    
    //State -> dp[i][j] = Maximum points till day i if activity j is chosen on day i
    //Transition -> dp[i][j] = a[i][j] + max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]);
    //Base Case -> dp[0][j] = a[0][j]
    //Final Subproblem -> max(dp[N-1][0], dp[N-1][1], dp[N-1][2])
    
    vector <vector<int>> dp(N, vector <int> (3, INT_MIN)); //State
    
    for(int j=0; j<3; j++) //Base Case
        dp[0][j] = a[0][j];
    
    
    for(int i=1; i<N; i++) //Transition
    {
        for(int j=0; j<3; j++)
            dp[i][j] = a[i][j] + max( dp[i-1][(j+1)%3], dp[i-1][(j+2)%3] );
    }
    
    cout << max( {dp[N-1][0], dp[N-1][1], dp[N-1][2]} );
    
    return 0;
}
