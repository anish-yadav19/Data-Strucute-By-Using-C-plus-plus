#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int>&q)
{
    stack<int>st;

    while(!q.empty())
    {
        int ele = q.front();
        q.pop();

        st.push(ele);
    }

    while(!st.empty())
    {
        int ele= st.top();
        st.pop();

        q.push(ele);
    }

}

void reverseQueueRec(queue<int>&q)
{
    if(q.empty())
    {
        return;
    }
    int temp = q.front();
    q.pop();

    reverseQueueRec(q);
    q.push(temp);
}
int main()
{
    queue<int>q;

    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);
    q.push(3);
    
    // reverseQueue(q);

    reverseQueueRec(q);

    cout<<"Printing Queue"<<endl;

    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;




    return 0;
}