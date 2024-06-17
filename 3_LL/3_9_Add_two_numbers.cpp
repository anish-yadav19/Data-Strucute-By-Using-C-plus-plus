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

Node* solve(Node* head1,Node* head2)
{
    if(head1 == NULL)
    {
        return head2;
    }
    if(head2 == NULL)
    {
        return head1;
    }
    // step1: reverse both linked list

    head1 = reverse(head1);
    head2 = reverse(head2);

    // step2: add both linked list
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;
    while(head1!=NULL && head2!=NULL)
    {
        int sum = carry + head1->data + head2->data;
        int digit = sum%10;
        carry = sum/10;

        Node* newNode = new Node(digit);
        if(ansHead == NULL)
        {
            ansHead = newNode;
            ansTail = newNode;
        }
        else
        {
            ansTail->next = newNode;
            ansTail = newNode;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    while(head1!=NULL)
    {
        int sum = carry + head1->data;
        int digit = sum%10;
        carry = sum/10;

        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head1 = head1->next;

    }

    
    while(head2!=NULL)
    {
        int sum = carry + head2->data;
        int digit = sum%10;
        carry = sum/10;

        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head2 = head2->next;

    }
    // handle carry alag se
    while(carry!=0)
    {
        int sum = carry;
        int digit = sum%10;
        carry = sum/10;

        Node* newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
    }


    // step3: reverse the ans linked list
    ansHead = reverse(ansHead);

    return ansHead;
}


int main()
{
    
    Node* head1 = new Node(2);
   
    insertAtHead(head1,4);
    // insertAtHead(head1,2);

    Node* head2 = new Node(2);
    insertAtHead(head2,3);
    insertAtHead(head2,4);
    

    print(head1);
    cout<<endl;

    
    
    
    
    print(head2);
    cout<<endl;

    Node* ans = solve(head1,head2);
    print(ans);

   
    return 0;
}