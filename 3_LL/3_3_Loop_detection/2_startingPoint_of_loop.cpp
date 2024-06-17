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
void print(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

bool checkForLoop(Node* &head)
{
    if(head == NULL)
    {
        return false;
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
        if(slow == fast)
        {
            return true;
        }
    }
    return false;
}
Node* startingPointOfLoop(Node* &head)
{
    if(head == NULL)
    {
        return head;
    }
    Node* slow = head;
    Node* fast = head;
    Node* temp = NULL;
    while(fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if(slow == fast)
        {
            temp = slow;
            slow = head;
            
            break;
        }

    }
    while(slow!=fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    int count = 0;
    while(temp!=fast)
    {
        
        fast = fast->next;
        count++;
    }
    cout<<"length of loop: "<<count<<endl;
    return slow;

}


int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80);
    Node* ninth = new Node(90);
    Node* tenth = new Node(100);
    Node* eleventh = new Node(110);

    
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = tenth;
    tenth->next = eleventh;
    eleventh->next = fourth;

    
    // print(first);
    cout<<"Loop is present or not "<<  checkForLoop(first)<<endl;
    cout<<"starting point of loop is: "<<startingPointOfLoop(first)->data<<endl;
    

    return 0;
}