#include<iostream>
#include<unordered_map>
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
    unordered_map<int,int>mpp;
    Node* curr = head;
    Node* prev =NULL;
    while(curr!=NULL)
    {
        mpp[curr->data]++;
        if(mpp[curr->data]>1)
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr= curr->next;
        }
    } 
    
}

int main()
{
    
    Node* head = new Node(1);
   
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,3);
    insertAtHead(head,5);
    insertAtHead(head,1);

    print(head);
    cout<<endl;

    removeDuplicates(head);
    
    print(head);
   
    return 0;
}