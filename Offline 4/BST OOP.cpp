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

    bool search(node* root, int key);
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

bool BST::search(node* temp_root, int data)
{
     bool is_found=false;

     while(temp_root!=NULL){
        if(data == temp_root->data){
            is_found=true;
            break;
        }
        else if(data <= temp_root->data){
            temp_root=temp_root->left;
        }
        else if(data >= temp_root->data){
            temp_root=temp_root->right;
        }
    }

    return is_found;
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
            node* temp = root->left;
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

    while(1)
    {
        int c;
        cout<<"1. insert"<<endl;
        cout<<"2. search"<<endl;
        cout<<"3. delete"<<endl;
        cout<<"4. inorder"<<endl;
        cout<<"5. preorder"<<endl;
        cout<<"6. exit"<<endl;
        cin>>c;
        if(c==1)
        {
            int k;
            cout<<"enter value to insert"<<endl;
            cin>>k;
            tree.insert(tree.getRoot(), k);
        }

        if(c==2)
        {
            int k;
            cout<<"enter value to search"<<endl;
            cin>>k;
            cout<<tree.search(tree.getRoot(), k)<<endl;
        }

        if(c==3)
        {
            int k;
            cout<<"enter value to delete"<<endl;
            cin>>k;
            tree.deleteNode(tree.getRoot(), k);
        }
        if(c==4)
        {
            tree.inorderTransversal(tree.getRoot());
        }
        if(c==5)
        {
            tree.preorderTransversal(tree.getRoot());
        }
        if(c==6)
        {
            break;
        }
    }


    return 0;
}
