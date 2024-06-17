#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>&st, int target)
{
    if(st.empty())
    {
        st.push(target);
        return;
    }
    if(st.top()>=target)
    {
        st.push(target);
        return;
    }

    int topElement = st.top();
    st.pop();
    insertAtBottom(st,target);

    st.push(topElement);
}
void sortStack(stack<int>&st)
{
    if(st.empty())
    {
        return;
    }

    int topElement = st.top();
    st.pop();

    sortStack(st);
    insertAtBottom(st,topElement);
}

int main()
{
    stack<int>st;
    st.push(5);
    st.push(8);
    st.push(1);
    st.push(80);
    st.push(20);
    st.push(3);
    st.push(12);

    sortStack(st);

    cout<<"printing"<<endl;
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    return 0;
}