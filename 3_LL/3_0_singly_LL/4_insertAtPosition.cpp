#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


void insertAtHead(Node* &head,Node* &tail, int data)
{
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        tail = newNode;
        head = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    
    
    head = newNode;

}
void insertAtTail(Node* &head,Node* &tail, int data)
{
     if(head == NULL)
    {
        Node* newNode = new Node(data);
        tail = newNode;
        head = newNode;
        return;
    }
    Node* newNode = new Node(data);

    // if LL is non-empty
        
    tail->next = newNode;

    tail = newNode;
}

void print(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int findLength(Node* head)
{
    Node* temp = head;
    int len = 0;
    while(temp!=NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void insertAtPosition(int data,int position, Node* &head,Node* &tail)
{
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if(position == 0)
    {
        insertAtHead(head,tail,data);
    }
    int len = findLength(head);
    cout<<len<<endl;
    if(position == len)
    {
        insertAtTail(head,tail,data);
    }

    // find the position: prev and curr
    int i= 1;
    Node* prev = head;
    while(i<position)
    {
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    Node* newNode = new Node(data);
    newNode->next = curr;
    prev->next = newNode;
}


int main()
{
    
    Node* head = NULL;
    Node* tail = NULL;
   
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,50);

    

    insertAtTail(head,tail,60);

    
    print(head);

    //insertAtPosition(101,0,head,tail);

    insertAtPosition(101,2,head,tail);

    // insertAtPosition(101,5,head,tail);


    print(head);
    
    

    return 0;
}