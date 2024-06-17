#include<iostream>
#include<queue>
using namespace std;
/*
class MyQueue {
public:
    queue<int>q1,q2;
    MyQueue() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        int temp = q1.front();
        q1.pop();
        return temp;
    }

    int peek() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

*/


// By using one queue
class MyQueue {
public:
    queue<int>q;
    MyQueue() {
        
    }
    
    void push(int x) 
    {
        q.push(x);
        for(int i = 0;i<q.size()-1;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }

    int peek() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
int main()
{
    MyQueue* obj = new MyQueue();
    obj->push(5);
    obj->push(10);
    obj->push(2);
    obj->push(8);
    obj->push(4);
    obj->push(15);

    int para1 = obj->pop();
    int para2 = obj->peek();
    bool para3 = obj->empty();

    cout<<para1<<" "<<para2<<" "<<para3<<endl;

    return 0;

    
}