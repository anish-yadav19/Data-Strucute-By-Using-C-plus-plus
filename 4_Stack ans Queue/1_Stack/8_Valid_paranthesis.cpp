#include<iostream>
#include<stack>
using namespace std;

bool isValid(string str, stack<char>&st)
{
    
    for(int i = 0;i<str.length();i++)
    {
        char ch = str[i];

        //opening bracket
        if(ch == '('|| ch == '{'|| ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if(!st.empty())
            {
                char c = st.top();
                
                if(ch == ')' && c == '(' )
                {
                    st.pop();
                }
                else if(ch== '}' && c =='{' )
                {
                    st.pop();
                }
                
                else if(ch == ']'&& c == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            } 
        }
        

    }
    if(st.empty()) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}
int main()
{
    stack<char>st;
    string str = "([[{}]])";

    bool ans = isValid(str,st);
    cout<<ans;

    
    return 0;
}