//ARIFUL_HRIDOY

#include<iostream>
using namespace std;

class Node
{
public :
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int x)
{
    Node* newNode = new Node(x);
    newNode->next = head;
    head = newNode;
}

void insertAtPosition(Node* head, int x, int pos)
{
    if(pos==0)
    {
        insertAtHead(head,x);
        return;
    }
    Node* newNode = new Node(x);
    Node* temp = head;
    int curr_pos = 0;
    while(curr_pos!=pos-1)
    {
        temp = temp->next;
        curr_pos++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtTail(Node* head, int x)
{
    Node* newNode = new Node(x);
    Node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(Node* head)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    Node* n = NULL;

    cout<<"1. Insert at head ()\n2. Insert at any position ()\n3. Insert at tail ()"<<endl;
    me :
        cout<<"Enter your choice : ";
    int c;
    cin>>c;

    switch(c)
    {
    case 1:
        {
            int x;
            cout<<"Enter value to insert at head : ";
            cin>>x;
            insertAtHead(n,x);
            display(n);
            goto me;
        }
    case 2 :
        {
            int pos,val;
            cout<<"Enter position to insert at : ";
            cin>>pos;
            cout<<"Value to insert at position "<<pos<<" : ";
            cin>>val;
            insertAtPosition(n,val, pos);
            display(n);
            goto me;
        }
    case 3 :
        {
            int x;
            cout<<"Enter value to insert at tail : ";
            cin>>x;
            insertAtTail(n,x);
            display(n);
            goto me;
        }
    default :
        {
            cout<<"Error choice!"<<endl;
            goto me;
        }
    }
    return 0;
}
