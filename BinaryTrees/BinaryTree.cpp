#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class node{
    public:
    int data;   
    node *left, *right;
    
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
    
};

node* buildTree(node *leaf){
    cout<<"\nEnter data: ";
    int d;
    cin>>d;    

    if(d==-1) return NULL;      

    leaf = new node(d);         //new node is created

    cout<<"To the left of "<<d;
    leaf->left=buildTree(leaf->left);
                                //the argument is passed to that an object can be created at that address
                                //"left->left" would hold the address of the new node which the function would return

    cout<<"To the right of "<<d;
    leaf->right=buildTree(leaf->right);         

    return leaf;                //address to the node is returned
}

void buildLevelOrder(node* &root){
    queue<node*> que;
    cout<<"Enter Data for the root: ";
    int d;
    cin>>d;
    root = new node(d);
    root = new node(d);
    que.push(root);

    while(!que.empty()){
        node *temp = que.front();
        que.pop();
        int d;
        cout<<"To the left of "<<temp->data<<": ";
        cin>>d;

        if(d!=-1){
            temp->left=new node(d);
            que.push(temp->left);
        }

        cout<<"To the right of "<<temp->data<<": ";
        cin>>d;

        if(d!=-1){
            temp->right=new node(d);
            que.push(temp->right);
        }
    }
}

void levelOrderTraversal(node *root){

    queue<node*> que;
    
    que.push(root);
    que.push(NULL);
    cout<<endl;
    while(!que.empty()){
        node* temp = que.front();
        que.pop();

        if(temp==NULL){
            cout<<endl;

            if(!que.empty())
                que.push(NULL);
        } else {

            cout<<temp->data<<" ";        

            if(temp->left)
                que.push(temp->left);

            if(temp->right)
                que.push(temp->right); 
        }
    }
}

void reverseOrderTraversal(node *root){

    //to do

}

void inOrderTraversal(node *root){
    if(root==NULL)
        return;
    
    if(root->left){
        inOrderTraversal(root->left);   
    }

    cout<<root->data<<" ";

    if(root->right){
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(node *root){
    if(root==NULL)
        return;

    cout<<root->data<<" ";

    if(root->left){
        preOrderTraversal(root->left);   
    }    

    if(root->right){
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(node *root){
    if(root==NULL)
        return;
    
    if(root->left){
        postOrderTraversal(root->left);   
    }    

    if(root->right){
        postOrderTraversal(root->right);
    }
    
    cout<<root->data<<" ";
}

int main(){
    node *root;
    
    // root=buildTree(root);
    buildLevelOrder(root);

    cout<<"Level Order Traversal: ";
    levelOrderTraversal(root);

    // reverseOrderTraversal(root);

    cout<<"In Order Taversal: ";
    inOrderTraversal(root);

    cout<<"\nPre Order Taversal: ";
    preOrderTraversal(root);

    cout<<"\nPost Order Taversal: ";
    postOrderTraversal(root);

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
}