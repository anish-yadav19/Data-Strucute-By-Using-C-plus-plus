#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* prev;
        Node* next;

    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* head)
{

    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp -> data<<" ";
        temp=temp->next;
    }
}
// t(n) = O(n)

int getLength(Node* head)
{
    int len = 0;
    Node* temp = head;
    while(temp!=NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
void insertAtHead(Node* &head,Node* &tail,int data)
{
    
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode= new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head= newNode;
}
void insertAtTail(Node* &head, Node* &tail,int data)
{
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode= new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail =newNode;
}
void insertAtPosition(int position,Node* &head,Node* &tail,int data)
{
    if(head == NULL)
        {
            Node* newNode = new Node(data);
            head = newNode;
            tail = newNode;
            return;
        }
    if(position == 1)
    {
        
        insertAtHead(head,tail,data);
        return;
    }
    int len = getLength(head);
    if(position > len)
    {
        insertAtTail(head,tail,data);
        return;
    }

    int i = 1;
    Node* prev = head;
    while(i<position-1)
    {
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;
    Node* newNode = new Node(data);
    newNode->next = curr;
    newNode->prev = prev;
    prev->next = newNode;
    curr->prev = newNode;
    
}


int main()
{

    
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->next = second;
    second->prev = first;
    
    second->next = third;
    third->prev= second;
    third->prev = second;


    Node* head = first;
    Node* tail = third;
    // insertAtHead(head,tail,101);
    // // insertAtHead(head,tail,201);
    // // insertAtHead(head,tail,301);
    // // insertAtHead(head,tail,401);
    // insertAtTail(head,tail,501);

    insertAtPosition(3,head,tail,601);

    print(head);

    
    return 0;
}