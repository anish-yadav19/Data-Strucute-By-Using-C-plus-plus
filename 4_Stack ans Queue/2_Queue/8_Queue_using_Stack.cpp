#include<iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        int temp = s1.top();
        s1.pop();
        return temp;
    }

    int peek() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
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