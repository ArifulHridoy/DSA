#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x)
    {
        data=x;
        left=nullptr;
        right=nullptr;
    }
};

Node* bstInsert(Node* root, int key)
{
    if(root==nullptr) return new Node(key);
    if(key<root->data) root->left=bstInsert(root->left,key);
    else root->right=bstInsert(root->right,key);
    return root;
}
void inorderTraversal(Node* root)
{
    if(root==nullptr) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root)
{
    if(root==nullptr) return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root)
{
    if(root==nullptr) return;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    cout<<root->data<<" ";
}

Node* searchBst(Node* root, int key)
{
    if(root==nullptr) return 0;
    if(key==root->data) return root;
    if(key>root->data) return searchBst(root->right,key);
    else return searchBst(root->left,key);
}

Node* inorderSuccessor(Node* root)
{
    Node* curr=root;
    while(curr && curr->left!=nullptr) curr=curr->left;
    return curr;
}

Node* deleteBst(Node* root, int key)
{
    if(key>root->data) root->right=deleteBst(root->right,key);
    else if(key<root->data) root->left=deleteBst(root->left,key);
    else
    {
        if(root->left==nullptr)
        {
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==nullptr)
        {
            Node* temp=root->left;
            free(root);
            return temp;
        }
        Node* temp=inorderSuccessor(root->right);
        root->data=temp->data;
        root->right=deleteBst(root->right,temp->data);
        return root;
    }
}

int main()
{
    Node* root=nullptr;
    root=bstInsert(root,2);
    root=bstInsert(root,4);
    root=bstInsert(root,5);
    root=bstInsert(root,1);
    root=bstInsert(root,3);
    root=bstInsert(root,6);

    if(searchBst(root,22)) cout<<"Found"<<endl;
    else cout<<"Not found!"<<endl;

    root=deleteBst(root,2);

    cout<<"Inorder : "; inorderTraversal(root);
    cout<<endl;
    cout<<"Preorder : "; preorderTraversal(root);
    cout<<endl;
    cout<<"Postorder : "; postorderTraversal(root);
    return 0;
}
