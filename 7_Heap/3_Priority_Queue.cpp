#include<iostream>
#include<queue>
using namespace std;

int main()
{

/*
    // max heap
    priority_queue<int>pq;

    pq.push(3);
    pq.push(10);
    pq.push(8);
    pq.push(5);
    pq.push(12);
    pq.push(1);

    pq.push(6);
    cout<<"Top element: "<<pq.top()<<endl;

    pq.pop();
    cout<<"top element: "<<pq.top()<<endl;

    */

   // Min heap

   priority_queue<int,vector<int>,greater<int>>pq;
    pq.push(3);
    pq.push(10);
    pq.push(8);
    pq.push(5);
    pq.push(12);
    pq.push(1);

    pq.push(6);

    cout<<"Top element: "<<pq.top()<<endl;

}