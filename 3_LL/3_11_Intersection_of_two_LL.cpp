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
    if(head1 == NULL || head2==NULL) return NULL;
    while(head2!=NULL)
    {
        Node* temp = head1;
        while(temp !=NULL)
        {
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    return NULL;
}
Node* solve1(Node* &head1,Node* &head2)
{
    if(head1 == NULL || head2==NULL) return NULL;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1->next && temp2->next)
    {
        if(temp1 == temp2)
        {
            return temp1;
        }
        temp1= temp1->next;
        temp2 = temp2->next;
    }

    if(temp1->next == NULL && temp2->next ==NULL && (temp1!=temp2)) 
    {
        cout<<"both LL are not intersected to each other"<<endl;
        return NULL;
    }
    if(temp1->next == NULL)
    {
        // temp2 LL is bigger
        // we need to find out how much bigger it is

        int temp2Len = 0;
        while(temp2->next)
        {
            temp2 = temp2->next;
            temp2Len++;
        }
        while(temp2Len--)
        {
            head2 = head2->next;
        }

    }

else
    {
        // temp1 LL is bigger
        // we need to find out how much bigger it is

        int temp1Len = 0;
        while(temp1->next)
        {
            temp1 = temp1->next;
            temp1Len++;
        }
        while(temp1Len--)
        {
            head1 = head1->next;
        }

    }

    while(head1!=head2)
    {
        head1= head1->next;
        head2 = head2->next;
    }
    return head1;
}

int main()
{
    
    
   
    Node* head1 = new Node(2);
    Node* second = new Node(3);
    Node* third = new Node(4);
    Node* fourth = new Node(5);
    Node* fifth = new Node(8);
    

    head1->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    // insertAtHead(head1,2);

    Node* head2 = new Node(6);
    
    Node* second1 = new Node(7);
    
    head2->next = second1;
    second1->next = fourth;
    
    print(head1);
    cout<<endl;

    print(head2);
    cout<<endl;
    // brute force
    Node* ans = solve(head1,head2);
    cout<<ans->data<<endl;

    Node* ans1 = solve1(head1,head2);
     cout<<ans1->data<<endl;

   
    return 0;
}