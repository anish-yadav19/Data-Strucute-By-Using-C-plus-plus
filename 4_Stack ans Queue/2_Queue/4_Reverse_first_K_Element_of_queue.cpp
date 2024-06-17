#include<iostream>
#include<queue>
#include<stack>
using namespace std;


void reverseK(queue<int>&q,int n, int k)
{
    if(k <= 0 || k>n)
    {
        return;
    }
    stack<int>st;
    int count = 0;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();

        st.push(temp);
        count++;

        if(count==k)
        {
            break;
        }
    }

    while(!st.empty())
    {
        int temp = st.top();
        st.pop();
        q.push(temp);
    }

    count = 0;
    while(!q.empty() && n-k!=0)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;

        if(count == n-k)
        {
            break;
        }
    }



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

    int n = q.size();
    reverseK(q,n,0);

    cout<<"printing"<<endl;
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    return 0;
}