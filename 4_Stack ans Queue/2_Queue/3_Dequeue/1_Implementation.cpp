#include<iostream>
using namespace std;

class Deque
{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void pushRear(int data)
    {
         if((front == 0 && rear == size-1) ||(rear == front-1))
        {
            cout<<"Q is full"<<endl;
            return;
        }
        else if(front == -1)
        {
            front = rear = 0;
           
        }
        else if(rear == size-1 && front!=0)
        {
            rear = 0;
            
        }
        else
        {
            rear++;
            
        }
        arr[rear] = data;
    }

    void pushFront(int data)
    {
        if((front == 0 && rear == size-1) ||(rear == front-1))
        {
            cout<<"Q is full"<<endl;
            return;
        }
        else if(front == -1)
        {
            front = rear = 0;
           
        }
        else if(front == 0 && rear!=size-1)
        {
            front = size-1;
            
        }
        else
        {
            front--;
            
        }
        arr[rear] = data;
    }

    void popRear()
    {
        if(front == -1)
        {
            cout<<"Q is empty"<<endl;
            return;
        }
        else if(front == rear)
        {
            arr[front] =-1;
            front = -1;
            rear = -1;
        }
        else if(rear == 0)
        {
            arr[rear] = -1;
            rear = size-1;
        }
        else 
        {
            arr[rear] = -1;
            rear--;
        }
        
    }

    void popFront()
    {
         if(front == -1)
        {
            cout<<"Q is empty"<<endl;
            return;
        }
        else if(front == rear)
        {
            arr[front] =-1;
            front = -1;
            rear = -1;
        }
        else if(front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
        
    }

    void print()
    {
        for(int i = 0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Deque dq(10);

    dq.pushFront(4);
    dq.pushFront(10);
    dq.pushRear(10);
    dq.pushRear(40);
    dq.pushRear(50);
    dq.pushRear(80);
    dq.print();

    dq.popFront();
    dq.popRear();
    dq.pushFront(103);
    dq.print();

    return 0;
    
}