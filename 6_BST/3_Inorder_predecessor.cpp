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
    Node(int item)
    {
        this->data = item;
        left = right = NULL;

    }
};
Node* newNode(int item )
{
    Node* temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;

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


Node* findPredecessor(Node* root, int p)
{
    Node* pred = NULL;
    Node* curr = root;
    while(curr)
    {
        if(curr->data <= p)
        {
            pred = curr;
            curr = curr->right;
        }
        else 
        {
            curr = curr->left;
        }
    }
    return pred;
}
int main()
{

    int key = 20;    //Key to be searched in BST
 
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
 
 
   Node* pred = findPredecessor(root,key);
   cout<<"Successor of "<<key<<" is: " << pred->data<<endl;
   
    return 0;
}