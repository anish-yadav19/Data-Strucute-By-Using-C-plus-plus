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

Node* reverse(Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* next = curr->next;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* solve(Node* &head1,Node* &head2)
{
    if(head1 == NULL && head2==NULL) return NULL;
    if(head1 == NULL && head2!=NULL) return head2;
    if(head2 == NULL && head1!=NULL) return head1;

    Node* left = head1;
    Node* right = head2;
    Node* mptr = new Node(-1);
    Node* ans = mptr;
    while(left && right)
    {

        if(left->data<=right->data)
        {
            ans->next = left;
            ans = left;
            left = left->next;
        }
        else
        {
            ans->next = right;
            ans= right;
            right = right->next;
        }
    }
    if(left)
    {
        ans->next = left;
        // ans = left;
        // left = left->next;
    }
    if(right)
    {
        ans->next = right;
        // ans= right;
        // right = right->next;
    }
    return mptr->next;

}


int main()
{
    
    
   
    Node* head1 = new Node(12);
    insertAtHead(head1,5);
    insertAtHead(head1,3);
    insertAtHead(head1,1);
    
    

    // insertAtHead(head1,2);

    Node* head2 = new Node(6);
    insertAtHead(head2,4);
    insertAtHead(head2,2);
   
    
    
    
    print(head1);
    cout<<endl;

    print(head2);
    cout<<endl;
    // brute force
    Node* ans = solve(head1,head2);
    print(ans);


   
    return 0;
}