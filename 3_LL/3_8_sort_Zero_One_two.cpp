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

void sortZeroOneTwo(Node* &head)
{
    int zero = 0;
    int one = 0;
    int two = 0;
    Node* temp = head;
    while(temp!=NULL)
    {
        if(temp->data ==0)
        {
            zero++;
        }
        else if(temp->data == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
        temp = temp->next;

    }

    temp = head;
    while(temp!=NULL)
    {
        while(zero--)
        {
            temp->data = 0;
            temp = temp->next;
        }
        while(one--)
        {
            temp->data = 1;
            temp = temp->next;
        }
        while(two--)
        {
            temp->data = 2;
            temp = temp->next;
        }
    }
}

Node* sort2(Node* &head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;
    while(curr!=NULL)
    {
        if(curr->data == 0)
        {
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            zeroTail->next =temp;
            zeroTail = temp; 

        }

        if(curr->data == 1)
        {
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            oneTail->next =temp;
            oneTail = temp; 
        }

        if(curr->data == 2)
        {
            Node* temp = curr;
            curr = curr->next;
            temp->next = NULL;

            twoTail->next =temp;
            twoTail = temp; 
        }
    }

    //delete dummy node of oneHead
    Node* temp = oneHead;
    oneHead=oneHead->next;
    temp->next = NULL;
    delete temp;

    // delete dummy node of twoHead
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    if(oneHead!=NULL)
    {
        // one wali list is non-empty
        zeroTail->next = oneHead;
        if(twoHead!=NULL)
        {
            // two wali list is non-empty
            oneTail->next  = twoHead;
        }
    }
        
    else
    {
        if(twoHead!=NULL)
        {
            zeroTail->next = twoHead;
        }
    }

    // delete zero wali dummy node
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    return zeroHead;
}

int main()
{
    
    Node* head = new Node(2);
   
    insertAtHead(head,2);
    insertAtHead(head,2);
    insertAtHead(head,2);
    insertAtHead(head,2);
    insertAtHead(head,2);

    print(head);
    cout<<endl;

    
    sortZeroOneTwo(head);
    print(head);
    cout<<endl;
    head = sort2(head);
    print(head);
   
    return 0;
}