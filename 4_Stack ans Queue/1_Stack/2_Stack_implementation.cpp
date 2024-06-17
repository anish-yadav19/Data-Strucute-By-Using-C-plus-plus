#include<iostream>
using namespace std;

class stack{
    // properties

    public:

    int *arr;
    int top;
    int size;

    stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    void push(int data)
    {
        if(size - top >1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout<<"Stack Overflow"<<endl;
        }

    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"Stack is underflow"<<endl;
        }
        else
        {
            // int item = stack[top];
            top--;
        }
    }
    int getTop()
    {
        if(top==-1) 
        {
            cout<<"There is no element in stack"<<endl;
        }
        else
        {
            return arr[top];
        }
    }
    int getSize()
    {
        return top+1;
    }
    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }



    // behaviour push(), pop(), top(), size(),empty()
};

int main()
{
    stack st(10);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout<<"Stack size: "<<st.getSize()<<endl;
    while(!st.isEmpty())
    {
        cout<<st.getTop()<<" ";
        st.pop();
    }
    cout<<endl;

    cout<<"Stack size: "<<st.getSize()<<endl;
    return 0;
}
