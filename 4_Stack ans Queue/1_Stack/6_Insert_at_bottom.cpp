// use only one stack
#include<iostream>
#include<stack>
using namespace std;


void insertAtbottom(stack<int>&st,int target)
{
    if(st.empty())
    {
        st.push(target);
        return;
    }
    int topElement = st.top();
    st.pop();
    insertAtbottom(st,target);

    st.push(topElement);
}

int main()
{
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(50);
    st.push(80);
    st.push(15);
    st.push(27);

    if(st.empty())
    {
        cout<<"stack is empty, cant insert at bottom"<<endl;
        
    }
    int target = st.top();
    st.pop();

    insertAtbottom(st,target);

    cout<<"Printing"<<endl;
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    return 0;
}
