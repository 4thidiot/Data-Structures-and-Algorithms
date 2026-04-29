#include <bits/stdc++.h>
using namespace std;

int n = 4;
int x[5];

bool valid(int k, int l)
{
    for(int i=1; i<k; i++)
    {
        if(x[i]==l || abs(i-k) == abs(x[i]-l))
            return false;
        return true;
    }
}

void NQueens(int k)
{
    for(int i=1; i<=n; i++)
    {
        if(valid(k,i)) //using bounding function k for current row for queen and i for (kth queen in ith column)
        {
            x[k] = i;
            if(k==n)
            {
                print(x);
                return;
            }
            NQueens(k+1);
        }
    }
}

int main() 
{
    cin>>n;
    NQueens(1);
}
