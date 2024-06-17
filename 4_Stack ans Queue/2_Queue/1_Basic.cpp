#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int>q;

    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(25);

    cout<<"size of quees is: "<<q.size()<<endl;
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    cout<<"size of quees is: "<<q.size()<<endl;

    q.push(50);
    cout<<"size of quees is: "<<q.size()<<endl;
    if(q.empty())
    {
        cout<<" Q is empty"<<endl;
    }
    else
    {
        cout<<" Q is not empty"<<endl;
    }
    return 0;
}