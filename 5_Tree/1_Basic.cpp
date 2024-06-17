#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
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

// it returns root node of the created tree
Node* createTree()
{
    cout<<"Enter the value for Node: "<<endl;

    int data;
    cin>>data;

    if(data == -1)
    {
        return NULL;
    }
    // step 1: create node

    Node* root = new Node(data);

    // step2 = create left subtree
    cout<<"left of Node: "<<root->data<<endl;
    root->left = createTree();

    // step3: create right subtree
    cout<<"right of Node: "<<root->data<<endl;
    root->right = createTree();

    return root;
}

void preOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    // root left right
    // root
    cout<<root->data<<" ";

    // left
    preOrderTraversal(root->left);

    // right
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    // left root right
    
    // left
    inOrderTraversal(root->left);

    // root
    cout<<root->data<<" ";

    // right
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    //  left right root
    
    // left
    inOrderTraversal(root->left);

    // right
    inOrderTraversal(root->right);

    // root
    cout<<root->data<<" ";
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

int heightOfTree(Node* root)
{
    if(root == NULL) return 0;
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    int height = max(leftHeight,rightHeight) + 1;
    return height;
}

int searchInorder(int inOrder[], int size, int target)
{
    for(int i = 0;i<size;i++)
    {
        if(inOrder[i] == target)
        {
            return i;
        }
    }
    return -1;
}

// creating map for searching index because it will take O(1) time
void createMapping(int inorder[],int size, map<int,int>&valueToIndexMap)
{
    for(int i = 0;i<size;i++)
    {
        int element=inorder[i];
        int index = i;
        valueToIndexMap[element] = index;
    }
}

Node* constructTreeFromPreAndInorderTraversal(map<int,int>&valueToIndexMap, int preOrder[],int inOrder[], int &preIndex,int inOrderStart, int inOrderEnd, int size)
{
    // base case 
    if(preIndex>=size || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    // 1 case main solve krta hu

    int element= preOrder[preIndex];
    preIndex++;
    Node* root = new Node(element);
    // element search krna prega inorder me

   // int position = searchInorder(inOrder,size, element);

    // finding position by using map
    int position = valueToIndexMap[element];


    // break recursion 
    root->left = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder,inOrder,preIndex, inOrderStart,position-1,size);
    root->right = constructTreeFromPreAndInorderTraversal(valueToIndexMap, preOrder,inOrder,preIndex,position+1,inOrderEnd,size);

    return root;
}

Node* constructTreeFromPostAndInorderTraversal(map<int,int>&valueToIndexMap, int postOrder[],int inOrder[], int &postIndex,int inOrderStart, int inOrderEnd, int size)
{
     if(postIndex < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    // 1 case main solve krta hu

    int element= postOrder[postIndex];
    postIndex--;
    Node* root = new Node(element);
    // element search krna prega inorder me

   // int position = searchInorder(inOrder,size, element);

    // finding position by using map
    int position = valueToIndexMap[element];


    // break recursion 
    // first right child call and then left child call becaue in postOrder traversal   L R Root ,so in reverse order first root then right then left
    root->right = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postOrder,inOrder,postIndex,position+1,inOrderEnd,size);
    root->left = constructTreeFromPostAndInorderTraversal(valueToIndexMap, postOrder,inOrder,postIndex, inOrderStart,position-1,size);
    

    return root;
}

int main()
{
    /*
    Node* root = createTree();
    cout<<"Printing Preorder: ";
    preOrderTraversal(root);
    cout<<endl;
    cout<<"Printing Inorder: ";
    inOrderTraversal(root);
    cout<<endl;

    cout<<"Printing Postorder: ";
    postOrderTraversal(root);
    cout<<endl;

    cout<<"Printing levelOrder: ";

    levelOrderTraversal(root);
    cout<<endl;

    // 5 10 15 -1 -1 12 -1 -1 20 -1 -1
    int height = heightOfTree(root);
    cout<<"Height of Tree: "<<height;

    */

/*
// this is for tree construction by using inorder and preorder

   int inorder[] = {10,8,6,2,4,12};
   int preOrder[] = {2,8,10,6,4,12};
   int size = 6;
   int preOrderIndex = 0;
   int inOrderStart = 0;
   int inOrderEnd = 5;
   map<int,int>valueToIndexMap;
   createMapping(inorder,size,valueToIndexMap);

   // this map is used to find the position of root node in O(1) time 

   Node* root = constructTreeFromPreAndInorderTraversal(valueToIndexMap,preOrder,inorder,preOrderIndex,inOrderStart,inOrderEnd,size);

   */
   
   int inorder[] = {8,14,6,2,10,4};
   int postorder[] = {8,6,14,4,10,2};
   int size = 6;
   int postIndex = size-1;
   int inOrderstart = 0;
   int inOrderend = size-1;

   map<int,int>valueToIndexMap;
   createMapping(inorder,size,valueToIndexMap);

   // this map is used to find the position of root node in O(1) time 

   Node* root = constructTreeFromPostAndInorderTraversal(valueToIndexMap,postorder,inorder,postIndex,inOrderstart,inOrderend,size);

   cout<<"printing the entire tree: "<<endl;
   levelOrderTraversal(root);

   
    return 0;
}