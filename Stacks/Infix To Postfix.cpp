//Understood from dsa course of Abdul Bari Ji but implemented the code myself using stl in c++
#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isOperator(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/')
        return true;
    else
        return false;
}

ll precedance(char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if (x=='/' || x=='*')
        return 2;
}

int main() 
{
	string s;
	cin>>s;
	
    stack <char> st;
    string postfix;
    
    for(int i=0; i<s.size(); i++)
    {
        if( !isOperator(s[i]) )
            postfix.push_back(s[i]);
        else
        {
            if( st.empty() || ( precedance(s[i]) > precedance(st.top()) ) )
                st.push(s[i]);
            else
            {
                while(!st.empty() && precedance(s[i]) <= precedance(st.top())) 
                { 
                    postfix.push_back(st.top()); 
                    st.pop();
                }
                // postfix.push_back(st.top());
                // st.pop();
                // st.push(s[i]);
            }
        }
    }
    while(!st.empty())
    {
        postfix.push_back(st.top());
        st.pop();
    }
    
    cout<<postfix;
    
    return 0;
}
