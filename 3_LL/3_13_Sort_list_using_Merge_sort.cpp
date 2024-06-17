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

// Node* reverse(Node* &head)
// {
//     Node* prev = NULL;
//     Node* curr = head;
//     Node* next = curr->next;
//     while(curr!=NULL)
//     {
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }
//     return prev;
// }
Node* findMid(Node* &head)
{
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


Node* merge(Node* &head1, Node* &head2)
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

Node* solve(Node* &head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    left = solve(left);
    right = solve(right);

    Node* mergeLL = merge(left,right);
    return mergeLL;

}


int main()
{
    
    
   
    Node* head = new Node(12);
    insertAtHead(head,5);
    insertAtHead(head,25);
    insertAtHead(head,1);
    insertAtHead(head,10);
    insertAtHead(head,8);
   
    
    
    
    print(head);
    cout<<endl;

    // print(head2);
    // cout<<endl;
    // // brute force
    Node* ans = solve(head);
    print(ans);


   
    return 0;
}