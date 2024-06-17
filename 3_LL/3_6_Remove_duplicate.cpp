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


void insertAtHead(Node* &head, int data)
{
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;

}


void print(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int getLength(Node* &head)
{
    Node* temp = head;
    int len = 0;
    while(temp!=NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void removeDuplicates(Node* &head)
{
    if(head == NULL)
    {
        cout<<"LL is empty"<<endl;
        return;
    }
    if(head->next == NULL)
    {
        cout<<"single Node in LL"<<endl;
        return;
    }
    Node* curr = head;
    while(curr!=NULL)
    {
        if((curr->next!=NULL) && curr->data == curr->next->data)
        {
            Node* temp = curr->next;

            curr->next = curr->next->next;
            temp->next = NULL;
            delete temp;
        }
        else{
            curr = curr->next;
        }
    }
    
}

int main()
{
    
    Node* head = new Node(1);
   
    insertAtHead(head,2);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,4);

    print(head);
    cout<<endl;

    removeDuplicates(head);
    
    print(head);
   
    return 0;
}