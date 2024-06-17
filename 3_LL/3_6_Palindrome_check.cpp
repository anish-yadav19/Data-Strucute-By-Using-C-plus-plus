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
bool checkPalindrome(Node* &head)
{
    if(head == NULL)
    {
        return true;
    }
    if(head->next == NULL)
    {
        return true;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

    }
    // slow pointer is pointing to middle node

    Node* rerverseKaHead = reverse(slow->next);
    slow->next = rerverseKaHead;

    Node* temp = head;
    Node* temp2 = rerverseKaHead;
    while(temp2!=NULL)
    {
        if(temp->data!=temp2->data)
        {
            return false;
        }
        temp = temp->next;
        temp2 = temp2->next;
    }
    return true;

}


int main()
{
    
    Node* head = new Node(10);
   
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,30);
    insertAtHead(head,50);
    insertAtHead(head,10);

    
    print(head);
    cout<<endl;

    bool isPalindrome = checkPalindrome(head);
    if(isPalindrome)
    {
        cout<<"LL is a valid Palindrome"<<endl;
    }
    else{
        cout<<"LL is not a valid Palindrome"<<endl;
    }
    

    return 0;
}