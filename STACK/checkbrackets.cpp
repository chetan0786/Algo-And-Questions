#include<bits/stdc++.h>

using namespace std;

bool checkBalanced(string s)
{
    stack<char> st;

    for (int  i = 0; i < s.length(); i++)
    {
        if(s[i]=='[' || s[i] =='(' || s[i]=='{')
            st.push(s[i]);
        else if(s[i]==']' || s[i] ==')' || s[i]=='}')
        { 
            if(st.top() == '(' && s[i] == ')' || st.top() == '[' && s[i] == ']' || st.top() == '{' && s[i] == '}')
                st.pop();
        }
    }

    if(st.empty())
        return true;
    return false;
}

int main()
{
    string s;
     cin>>s;

    cout<<checkBalanced(s);
}
