#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int val;
    Node *left, *right;

    Node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

Node *insertIntoBST(Node *root, int value)
{
    if (!root)
    {
        root = new Node(value);
        return root;
    }

    if (value > root->val)
    {
        root->right = insertIntoBST(root->right, value);
    }
    else
    {
        root->left = insertIntoBST(root->left, value);
    }
    return root;
}

Node *deleteFromBST(Node *root, int value){
    if(!root)
        return NULL;

    if(root->val == value){
        if(!root->left && !root->right){
            delete(root);
            return NULL;
        } 

        if(root->left==NULL ^ root->right==NULL){
            Node* temp = root;
            if(root->left){
                root = root->left;
            } else {
                root = root->right;
            }
            delete(temp);
            return root;

        } else {

            Node *temp = root->right;
            while(temp->left)
                temp = temp->left;
            root->val = temp->val;

            root->right = deleteFromBST(root->right, temp->val);
        }

    } else {
        if(root->val < value){
            root->right = deleteFromBST(root->right, value);
        } else {
            root->left = deleteFromBST(root->left, value);
        }
    }

    return root;
}

Node *makeTree(Node *root)
{
   int value;
   cout<<"Enter values to be inserted into the tree:";
    cin >> value;

    while (value != -1)
    {
        root = insertIntoBST(root, value);
        cin >> value;
    }

    return root;
}

void levelOrderTraversal(Node *root){

    queue<Node*> que;
    
    que.push(root);
    que.push(NULL);
    cout<<endl;
    while(!que.empty()){
        Node* temp = que.front();
        que.pop();

        if(temp==NULL){
            cout<<endl;

            if(!que.empty())
                que.push(NULL);
        } else {

            cout<<temp->val<<" ";        

            if(temp->left)
                que.push(temp->left);

            if(temp->right)
                que.push(temp->right); 
        }
    }
}

int main()
{
    Node *root;
    root = makeTree(root);
    levelOrderTraversal(root);
    root = deleteFromBST(root, 70);
    levelOrderTraversal(root);
}