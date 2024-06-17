#include<iostream>
using namespace std;

class Cqueue
{

    public:
    int *arr;
    int size;
    int rear;
    int front;

    Cqueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void push(int data)
    {
        if((front == 0 && rear == size-1) ||(rear == front-1))
        {
            cout<<"Q is full"<<endl;
            return;
        }
        else if(front == -1)
        {
            front = rear = 0;
            arr[rear] = data;
        }
        else if(rear == size-1 && front!=0)
        {
            rear = 0;
            arr[rear] = data;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }
    void pop()
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
            front = 0;
        }
        else
        {
            front++;
        }
    }
    
    void displayQueue()
    {
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ",arr[i]);
    }
    else
    {
        for (int i = front; i < size; i++)
            printf("%d ", arr[i]);
 
        for (int i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
    }
    }   
    
};

int main()
{
    Cqueue q(10);
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.push(25);
    
    q.displayQueue();

    q.pop();
    q.pop();

    

    q.push(18);
    q.push(24);
    
    q.displayQueue();

    q.push(12);



    return 0;
}