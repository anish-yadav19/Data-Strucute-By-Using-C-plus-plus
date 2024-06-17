#include<iostream>
using namespace std;

class stack
{
    public:
        int *arr;
        int size;
        int top1;
        int top2;

    stack(int size)
    {
        arr= new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    void push1(int data)
    {
        if(top2 - top1 == 1)
        {
            cout<<"overflow in stack1"<<endl;
        }
        else
        {
            top1++;
            arr[top1] = data;
        }
    }
    void pop1()
    {
        if(top1 == -1)
        {
            cout<<"underflow in stack1"<<endl;
        }
        else
        {
            // int rem = stack[top1];
            top1--;
            // delete(rem);
        }
    }

    void push2(int data)
    {
        if(top2 - top1 == 1)
        {
            cout<<"overflow in stack2"<<endl;
        }
        else
        {
            top2--;
            arr[top2] = data;
        }
    }
    void pop2()
    {
        if(top2 == size)
        {
            cout<<"underflow in stack2"<<endl;
        }
        else
        {
            top2++;
        }
    }

    void print()
    {
        cout<<endl;
        cout<<" top1: "<<top1<<endl;
        cout<<" top2: "<<top2<<endl;
        for(int i = 0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
       


};

int main()
{
    stack st(8);

    st.push1(10);
    st.print();
    st.push1(20);
    st.print();
    st.push1(30);
    st.print();
    st.push1(40);
    st.print();
    


    st.push2(100);
    st.print();
    st.push2(200);
    st.print();
    st.push2(220);
    st.print();
    st.push2(240);
    st.print();
    // st.push2(280);
    // st.print();

    st.pop1();
    st.print();
    st.pop1();
    st.print();
    st.pop1();
    st.print();
    st.pop1();
    st.print();

    st.push2(280);
    st.print();
    st.pop1();
    st.print();



    return 0;
}