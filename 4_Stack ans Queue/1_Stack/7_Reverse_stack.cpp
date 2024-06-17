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
void reverseStack(stack<int>&st)
{
    if(st.empty())
    {
        return;
    }
    int target = st.top();
    st.pop();

    reverseStack(st);

    insertAtbottom(st,target);
}
int main()
{
    stack<int>st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    reverseStack(st);

    cout<<"printing"<<endl;

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    return 0;


}