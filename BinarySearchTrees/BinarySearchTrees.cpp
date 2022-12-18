#include <iostream>

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

Node *makeTree(Node *root)
{

    int value;
    cin >> value;

    while (value != -1)
    {
        root = insertIntoBST(root, value);
        cin >> value;
    }

    return root;
}

int main()
{
    Node *root;
    root = makeTree(root);
}