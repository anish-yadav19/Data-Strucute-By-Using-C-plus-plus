#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node()
    {

    }

	Node(int x)
    {
	    data = x;
	    left = NULL;
	    right = NULL;
    }
};

Node* newNode(int item )
{
    Node* temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;

}
void inOrderTraversal(Node* root,Node* &prev)
{
    if(root == NULL)
    {
        return;
    }
   
    inOrderTraversal(root->left,prev);
    prev->left = 0;
    prev->right = root;
    prev = root;
    inOrderTraversal(root->right,prev);
}


Node* insert(Node* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->data)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

Node* findSuccessor(Node* root, int p)
{
    Node* succ = NULL;
    Node* curr = root;
    while(curr)
    {
        if(curr->data > p)
        {
            succ = curr;
            curr = curr->left;
        }
        else 
        {
            curr = curr->right;
        }
    }
    return succ;
}

Node* flatten(Node* root)
{
    Node* dummy = new Node(-1);
    Node* prev = dummy;
    inOrderTraversal(root,prev);
    prev->left = prev->right = 0;
    root = dummy->right;

    return root;
}


void printLL(Node* head) 
{
    Node* temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
}
int main()
{

    int key = 50;    //Key to be searched in BST
 
   /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
 
//    Node* pred = findSuccessor(root,key);
//    cout<<"Successor of "<<key<<" is: " << pred->data<<endl;

root = flatten(root);
printLL(root);
   
    return 0;
}