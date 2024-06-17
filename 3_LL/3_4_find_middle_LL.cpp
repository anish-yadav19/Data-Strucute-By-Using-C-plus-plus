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
        this->next =NULL;
    }
};

int getLength(Node* &head)
{
    int len = 0;
    Node* temp = head;
    while(temp!=NULL)
    {
        temp=temp->next;
        len++;
    }
    return len;
}
void insertAtHead(Node* &head,int data)
{
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void print(Node* &head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
Node* middleNode(Node* &head,int len)
{
    if(len%2==0)
    {
        int i = 0;
        int mid = len/2;
        Node* temp = head;
        while(i<mid-1)
        {
            temp = temp->next;
            i++;
        }
        return temp;

    }
    else
    {
        int i = 0;
        int mid = len/2;
        Node* temp = head;
        while(i<mid)
        {
            temp = temp->next;
            i++;
        }
        return temp;
    }
}

Node* middleNodeByUsingFast_Slow(Node* &head)
{
    if(head == NULL)
    {
        return head;
    }
    if(head->next == NULL)
    {
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(slow!=NULL && fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;

}

int main()
{
    Node* head = new Node(5);
    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);
    insertAtHead(head,50);
    print(head);
    cout<<endl;
    // insertAtHead(head,60);
    // int len = getLength(head);
    // Node* ans = middleNode(head,len);
    Node* ans = middleNodeByUsingFast_Slow(head);
    cout<<ans->data<<endl;

    
    return 0;
}