#include <bits/stdc++.h>
using namespace std;

int main() 
{
	stack <char> st;
	
	string s;
	cin>>s;
	
	bool ans=false;
	
	for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
            st.push('(');
        else if(s[i]==')')
        {
            if(!st.empty())
                st.pop();
            else
                break;
        }
    }
    if(st.empty())
        ans = true;
    
    cout<<ans;
    
    return 0;
}
