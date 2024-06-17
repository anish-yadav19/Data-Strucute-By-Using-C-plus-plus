#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class NodeData
{

    public:
    int size;
    int minVal;
    int maxVal;
    bool validBST;

    NodeData()
    {

    }

    NodeData(int size,int max,int min,bool valid)
    {
        this->size = size;
        minVal = min;
        maxVal = max;
        validBST = valid;
    }
};

Node* insertIntoBST(Node* root, int data)
{
    if(root == NULL)
    {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // 

    if(root->data>data)
    {
        root->left = insertIntoBST(root->left,data);
    }
    else
    {
        root->right = insertIntoBST(root->right,data);
    }

    return root;
}

void takeInput(Node* &root)
{
    int data;
    cin>>data;

    while(data!=-1)
    {
        root = insertIntoBST(root,data);
        cin>>data;
    }


}
void preOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    cout<< root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }
   
    inOrderTraversal(root->left);
    cout<< root->data<<" ";
    inOrderTraversal(root->right);
}


void postOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<< root->data<<" ";
}

void levelOrderTraversal(Node* root)
{
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* front = q.front();
        q.pop();
        if(front == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout<<front->data<<" ";

            if(front->left!=NULL)
            {
                q.push(front->left);

            }
            if(front->right !=NULL)
            {
                 q.push(front->right);
            }
        }
        
    }
}

// assuming there are only unique values
Node* findNodeInBST(Node* root, int target)
{
    if(root == NULL) return NULL;

    if(root->data == target)
    {
        return root;
    }

    // bool leftAns = false;
    // bool rightAns = false;
    if(root->data>target)
    {
        return findNodeInBST(root->left,target);
    }
    else
    {
        return findNodeInBST(root->right,target);
    }
   
}


int minVal(Node* root)
{
    Node* temp = root;
    if(temp == NULL) return -1;
    while(temp->left!=NULL)
    {
        temp = temp->left;
    }
    return temp->data;

}

int maxVal(Node* root)
{
    Node* temp = root;
    if(temp == NULL) return -1;
    while(temp->right !=NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

Node* deleteNodeInBST(Node* root, int target)
{
    if(root == NULL) return root;

    if(root->data == target)
    {
        // isi ko delete krni h
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if(root->left == NULL && root->right!=NULL)
        {
            Node* child = root->right;
            delete root;
            return child;
        }
        else if(root->left!=NULL && root->right == NULL)
        {
            Node* child =root->left;
            delete root;
            return child;
        }
        else
        {
            // both child
            // find inorder predecessor in left subtree
            int inorderPre = maxVal(root->left);
            root->data = inorderPre;
            root->left = deleteNodeInBST(root->left,target);
            return root;
        }
    }
    else if(target>root->data)
    {
        root->right= deleteNodeInBST(root->right,target);
    }

    else if(target<root->data)
    {
        root->left =  deleteNodeInBST(root->left,target);
    }
    return root;


    

}

Node* bstUsingInorder(int inorder[], int s, int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid = (s+e)/2;
    int element = inorder[mid];

    Node* root= new Node(element);

    root->left = bstUsingInorder(inorder,s,mid-1);
    root->right = bstUsingInorder(inorder,mid+1,e);
    return root;

}

void convertIntoSortedDLL(Node* root,Node* &head)
{
    if(root == NULL)
    {
        return;
    }

    // right subtree
    convertIntoSortedDLL(root->right,head);
    root->right = head;
    if(head !=NULL)
    {
        head->left = root;
    }

    // update head
    head = root;

    // left subtree
    convertIntoSortedDLL(root->left,head);
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

Node* sortedLLIntoBST(Node* &head,int n)
{
    if(n<=0 || head == NULL)
    {
        return NULL;
    }
    Node* leftSubtree = sortedLLIntoBST(head, n-1-n/2);
    Node* root =head;
    root->left = leftSubtree;
    head = head->right;

    root->right = sortedLLIntoBST(head, n/2);

    return root;


}

NodeData findLargestBST(Node* root, int &ans)
{
    if(root == NULL)
    {
        NodeData temp(0,INT_MIN, INT_MAX,true);
        return temp;
    }

    NodeData leftAns = findLargestBST(root->left, ans);

    NodeData rightAns = findLargestBST(root->right, ans);

    // checking start here

    NodeData currNodeAns;
    currNodeAns.size = leftAns.size + rightAns.size + 1;
    currNodeAns.maxVal = max(root->data,rightAns.maxVal);
    currNodeAns.minVal = min(root->data,leftAns.minVal);

    if(leftAns.validBST && rightAns.validBST && root->data>leftAns.maxVal && root->data < rightAns.minVal)
    {
        currNodeAns.validBST = true;
    }
    else
    {
        currNodeAns.validBST = false;
    }

    if(currNodeAns.validBST)
    {
        ans = max(ans, currNodeAns.size );

    }

    return currNodeAns;

}



int main()
{


    
   /*
    Node* root = NULL;
    cout<<"enter the data for Node: "<<endl;

    takeInput(root);



    cout<<"Printing the tree: "<<endl;
    levelOrderTraversal(root);

    cout<<endl;

    */

    

    // cout<<"preOrder: "<<endl;
    // preOrderTraversal(root);

    // cout<<endl;

    // cout<<"inOrder: "<<endl;
    // inOrderTraversal(root);

    // cout<<endl;

    // cout<<"postOrder: "<<endl;
    // postOrderTraversal(root);

    // cout<<endl;

    // bool ans = findNodeInBST(root,40);
    // cout<<ans;

    // cout<<endl;

    // cout<<"Minimum Value: "<< minVal(root)<<endl;

    // cout<<"Maximum value: "<<maxVal(root)<<endl;


    // root =deleteNodeInBST(root,100);
    // levelOrderTraversal(root);


    

    //10 20 5 11 17 2 4 8 6 25 15 -1



    // 100 50 150 40 60 175 110 -1

/*
// BST using inorder
    
    int inorder[] = {1,2,3,4,5,6,7,8,9};
    int s = 0;
    int e = 8;

    Node* root =bstUsingInorder(inorder,s,e);
    levelOrderTraversal(root);

    Node* head = NULL;
    convertIntoSortedDLL(root,head);
    printLL(head);

    // convert from sorted LL to BST
    Node* root1 = NULL;
    root1 = sortedLLIntoBST(head,9);
    cout<<" Doping level order traversal for root1: "<<endl;
    levelOrderTraversal(root1);
*/


    // finding largest BST in Bt
    Node* root = new Node(5);
    Node* first = new Node(2);
    Node* second = new Node(4);
    Node* third = new Node(1);
    Node* fourth = new Node(3);

    root->left = first;
    root->right = second;
    first->left = third;
    first->right = fourth;

    cout<<"Printing the tree : "<<endl;
    levelOrderTraversal(root);
    
    int ans = 0;
    findLargestBST(root,ans);
    cout<<"Largest BST ka size: "<<ans<<endl;
    
    return 0;
}