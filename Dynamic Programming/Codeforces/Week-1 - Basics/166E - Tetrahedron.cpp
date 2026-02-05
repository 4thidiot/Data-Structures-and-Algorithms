#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
#define int long long 

signed main() 
{
	int n;
	cin>>n;
	
	//State -> dpD[i] = ways to be at D after i moves                                  dpX[i] = ways to be at X after i moves
	//Base Case -> dpD[0] = 1                                                              dpX[0] = 0
	//Transition -> dpD[i] = dpX[i-1]                                                       dpX[i] = 3*dpD[i-1] + 2*dpX[i-1]
	//Final Subproblem -> dpD[n]
	
	vector <int> dpD(n+1, 0), dpX(n+1, 0); //State and second base case handled here
	dpD[0] = 1, dpX[0] = 0; //Base case
	
	for(int i=1; i<=n; i++) //Transition
	{
	    dpD[i] = dpX[i-1] % MOD;
	    dpX[i] = (3*dpD[i-1] + 2*dpX[i-1]) % MOD;
	}
	
	cout << dpD[n]; //Final Subproblem 
    
    return 0;
}
