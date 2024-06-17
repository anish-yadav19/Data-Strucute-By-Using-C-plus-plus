#include<iostream>
#include<unordered_map>
using namespace std;



class Node
{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        this->data = val;
        next = NULL;
    }
    Node()
    {

    }
};


bool checkCircular(Node* head)
{
    unordered_map<Node*,bool>vis;
    Node* temp = head;
    while(temp!=NULL)
    {
        if(vis.find(temp)!=vis.end())
        {
            vis[temp] = true;
        }
        else
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int main()
{

    Node* head = new Node(NULL);

    checkCircular(head);
    return 0;
}