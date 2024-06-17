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
    cout<<endl;
}
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


// by using reverse

// Node* reverseLL(Node* &prev,Node* &curr)
// {
//     if(curr == NULL)
//     {
//         return prev;
//     }

//     Node* next = curr->next;
//     curr->next = prev;
//     reverseLL(curr,next);
// }

// by using loop

// Node* reverseUsingLoop(Node* &head)
// {
//     Node* prev = NULL;
//     Node* curr = head;

//     while(curr !=NULL)
//     {
//         Node* temp = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = temp;
//     }
//     return prev;
// }
Node* reverseInGroups(Node* &head,int k)
{
    if(head == NULL)
    {
        cout<<"LL is empty"<<endl;
        return head;
    }
    int len = getLength(head);
    
    if(k > len)
    {
        // cout<<"enter valid value of K"<<endl;
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* next = curr->next;
    int count = 0;
    while(count<k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next!=NULL)
    {
        head->next =  reverseInGroups(next,k);
    }
    return prev;
    

}

int main()
{
    
    Node* head = new Node(10);
   
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);
    insertAtHead(head,50);
    insertAtHead(head,60);
    insertAtHead(head,70);
    insertAtHead(head,80);

    print(head);

    // Node* prev = NULL;
    // Node* curr = head;
    // head = reverseLL(prev,curr);
    // head = reverseUsingLoop(head);
    head = reverseInGroups(head,2);
    
    print(head);
    
    

    return 0;
}