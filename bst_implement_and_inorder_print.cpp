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

int main()
{
    Node* root=nullptr;
    root=bstInsert(root,7);
    root=bstInsert(root,2);
    root=bstInsert(root,3);
    root=bstInsert(root,1);
    root=bstInsert(root,5);
    root=bstInsert(root,9);
    inorderTraversal(root);
    return 0;
}
