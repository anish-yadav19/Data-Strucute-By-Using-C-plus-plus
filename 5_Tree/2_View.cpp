#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTree()
{
    cout<<"Enter the  value of Node: ";
    int value;
    cin>>value;

    if(value == -1)
    {
        return NULL;
    }
    
    // create Node;
    Node* root = new Node(value);
    cout<<"Entering in left of : "<<value <<endl;
    root->left = createTree();
    cout<<"Entering in right of: "<<value<<endl;
    root->right = createTree();

    return root;
}

void preOrder(Node* root)
{
    if(root == NULL) return;
    
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root)
{
    if(root == NULL) return;
    
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(Node* root)
{
    if(root == NULL) return;
    
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(Node* root)
{
    if(root ==NULL) return;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    cout<<endl;
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }

    }
}
void printLeftView(Node* root, int level, vector<int>&ans)
{
    if(root == NULL) return;

    if(level == ans.size())
    {
        ans.push_back(root->data);
    }

    printLeftView(root->left, level+1, ans);
    printLeftView(root->right, level+1, ans);


}

void printRightView(Node* root, int level, vector<int>&ans)
{
    if(root == NULL) return;

    if(level == ans.size())
    {
        ans.push_back(root->data);
    }

    
    printRightView(root->right, level+1, ans);
    printRightView(root->left, level+1, ans);


}
void printTopView(Node* root)
{
    map<int, int>mpp;
    queue<pair<Node*,int>>q;
    q.push({root,0});

    while(!q.empty())
    {
        pair<Node* , int>temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;
        // if there is no entry of hd in mamp the create  a new entry

        if(mpp.find(hd) == mpp.end())
        {
            mpp[hd] = frontNode->data;
        }

        if(frontNode->left!=NULL)
        {
            q.push({frontNode->left,hd-1});
        }
        if(frontNode->right!=NULL)
        {
            q.push({frontNode->right,hd+1});
        }
    }

    cout<<"printing top view: "<<endl;

    for(auto it: mpp)
    {
        cout<<it.second<<" ";
    }
    cout<<endl;

}

void printBottomView(Node* root)
{
    map<int, int>mpp;
    queue<pair<Node*,int>>q;
    q.push({root,0});

    while(!q.empty())
    {
        pair<Node* , int>temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;
        // if there is no entry of hd in mamp the create  a new entry

        // overwrite answer so that the deeper nodes can be stored
        mpp[hd] = frontNode->data;
        

        if(frontNode->left!=NULL)
        {
            q.push({frontNode->left,hd-1});
        }
        if(frontNode->right!=NULL)
        {
            q.push({frontNode->right,hd+1});
        }
    }

    cout<<"printing Bottom view: "<<endl;

    for(auto it: mpp)
    {
        cout<<it.second<<" ";
    }
    cout<<endl;
}

void printLeftBoundary(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    if(root->left!=NULL)
    {
        printLeftBoundary(root->left);
    }
    else
    {
        printLeftBoundary(root->right);
    }
}

void printLeafBoudary(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    if(root->left == NULL && root->right == NULL)
    {
        cout<<root->data<<" ";
    }
    printLeafBoudary(root->left);
    printLeafBoudary(root->right);
}

void printRightBoundary(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return;
    }
    
    if(root->right!=NULL)
    {
        printRightBoundary(root->right);
    }
    else
    {
        printRightBoundary(root->left);
    }
    cout<<root->data<<" ";
}

void boundaryTraversal(Node* root)
{
    if(root == NULL) return;
    printLeftBoundary(root);
    cout<<endl;
    printLeafBoudary(root);
    cout<<endl;
    if(root->right!=NULL)
    {
        printRightBoundary(root->right);
    }
    else
    {
        printRightBoundary(root->left);
    }
    
}

int main()
{ 

    // 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1
    Node* root = createTree();
    levelOrder(root);
    
    vector<int>leftview;

    printLeftView(root,0,leftview);
    cout<<"printing left view: "<<endl;

    for(int i = 0;i<leftview.size();i++)
    {
        cout<<leftview[i]<<" ";
    }
    cout<<endl;

    vector<int>rightview;
    printRightView(root,0,rightview);
    cout<<"printing right view: "<<endl;

    for(int i = 0;i<rightview.size();i++)
    {
        cout<<rightview[i]<<" ";
    }
    cout<<endl;

    printTopView(root);

    printBottomView(root);

    boundaryTraversal(root);


    return 0;
}
