#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;
};

class BST
{
    node* Root=NULL;
public:

    node* search(node* root, int key);
    node* insert(node* Node, int key);
    node* deleteNode(node* Node, int key);
    void inorderTransversal(node* root);
    void preorderTransversal(node* root);
    node* newNode(int key);
    node* minValueNode(node* Node);
    node* getRoot()
    {
        return Root;
    }
};

node* BST::newNode(int key)
{
    node* temp = new node();
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

node* BST::minValueNode(node* Node)
{
    node* current = Node;
    while(current->left != NULL)
        current = current->left;
    return current;
}

node* BST::search(node* root, int key)
{
    if(root==NULL || root->data == key)
        return root;
    if(root->data > key)
        search(root->right, key);
    else if(root->data < key)
        search(root->left, key);
}

node* BST::insert(node* Node, int key)
{
    if(Root==NULL)
    {
        Root= newNode(key);
        return Root;
    }
    if(Node==NULL)
        return newNode(key);
    if(key < Node->data)
        Node->left= insert(Node->left, key);
    else if(key > Node->data)
        Node->right=insert(Node->right, key);


}

node* BST::deleteNode(node* root, int key)
{
    if(root==NULL)
        return root;
    if(key< root->data)
        root->left = deleteNode(root->left, key);
    else if(key> root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if(root->left == NULL)
        {
            node* temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right == NULL)
        {
            node* temp = root->right;
            free(root);
            return temp;
        }
        node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void BST::inorderTransversal(node* root)
{
    if(root!=NULL)
    {
        inorderTransversal(root->left);
        cout<<root->data<<endl;
        inorderTransversal(root->right);
    }
}

void BST::preorderTransversal(node* root)
{
    if(root!=NULL)
    {
        cout<<root->data<<endl;
        inorderTransversal(root->left);
        inorderTransversal(root->right);
    }
}

int main()
{
    BST tree;
    tree.insert(tree.getRoot(), 50);
    tree.insert(tree.getRoot(), 30);
    tree.insert(tree.getRoot(), 20);
    tree.insert(tree.getRoot(), 40);
    tree.insert(tree.getRoot(), 70);
    tree.insert(tree.getRoot(), 60);
    tree.insert(tree.getRoot(), 80);
    tree.inorderTransversal(tree.getRoot());
    tree.deleteNode(tree.getRoot(),50);
    tree.inorderTransversal(tree.getRoot());


    return 0;
}
