#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int>dq;

    dq.push_front(5);
    dq.push_front(10);
    dq.push_back(20);
    dq.push_back(30);

    cout<<"size: "<<dq.size()<<endl;

    dq.pop_front();

    cout<<"size: "<<dq.size()<<endl;

    dq.pop_back();

    cout<<"size: "<<dq.size()<<endl;

    cout<<"Front: "<<dq.front()<<endl;
    cout<<"Back: "<<dq.back()<<endl;

    return 0;
}