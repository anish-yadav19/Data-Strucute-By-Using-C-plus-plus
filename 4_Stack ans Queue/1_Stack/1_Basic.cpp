#include<iostream>
#include<stack>
using namespace std;

int main()
{
    // stack<int>st;
    // st.push(20);
    // st.push(30);
    // st.push(40);
    // st.push(50);
    // st.push(60);
    // st.push(70);

    // st.pop();

    // cout<<"Top on the stack: "<< st.top()<<endl;

    // cout<<"size of stack: "<<st.size()<<endl;

    // if(st.empty())
    // {
    //     cout<<"Stack is empty"<<endl;

    // }
    // else
    // {
    //     cout<<"stack is not empty"<<endl;
    // }

    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(!s.empty())
    {
        cout<<s.top() << " ";
        s.pop();
    }

    return 0;
}