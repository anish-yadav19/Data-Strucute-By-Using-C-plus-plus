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

Node* rotateList(Node* &head,int k)
{
    if(head == NULL) return NULL ;
    int len = getLength(head);
    int actK = k%len;
    if(actK == 0) return head;
    int rem = len - k - 1;
    
    Node* newlast = head;
    
    while(rem--)
    {
        newlast = newlast->next;

    }
    Node* newhead = newlast->next;
    newlast->next = NULL;

    Node* itr = newhead;
    while(itr->next)
    {
        itr = itr->next;
    }
    itr->next = head;
    return newhead;

}
int main()
{
    
    Node* head = new Node(8);
   
    insertAtHead(head,2);
    insertAtHead(head,10);
    insertAtHead(head,3);
    insertAtHead(head,5);
    insertAtHead(head,6);

    print(head);
    cout<<endl;

     Node* ans = rotateList(head,2);
    
     print(ans);
   
    return 0;
}