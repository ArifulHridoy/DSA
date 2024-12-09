#include<iostream>
using namespace std;

class Node
{
public :
    int data;
    Node* next;

    Node(int v)
    {
        data = v;
        next = NULL;
    }

};

void deleteAtHead(Node* &head)
{
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtTail(Node* &head)
{
    Node* second_last = head;
     while(second_last->next->next!=NULL)
      {
         second_last = second_last->next;
      }

    Node* temp = second_last->next;
    second_last->next=NULL;
    free(temp);
}

void deleteAtPosition(Node* &head, int pos)
{
    if(pos==0)
    {
        deleteAtHead(head);
        return;
    }
    Node* temp = head;
    int current_pos = 0;
    while(current_pos!= pos-1)
    {
        temp = temp->next;
        current_pos++;
    }

    Node* x = temp->next;
    temp->next=temp->next->next;
    free(x);
}

void insertAtHead(Node* &head, int x)
{
    Node* newNode = new Node(x);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node* &head, int x)
{
    Node* newNode = new Node(x);
    Node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(Node* &head, int x, int pos)
{
    if(pos==0)
    {
        insertAtHead(head,x);
        return;
    }

    Node* newNode = new Node(x);
    Node* temp = head;
    int current_pos = 0;
    while(current_pos!=pos-1)
    {
        temp = temp->next;
        current_pos ++;
    }
    newNode->next = temp->next;
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
    cout<<endl;
}
 int main()
 {
     Node* n = NULL;
     insertAtHead(n,1);
     display(n);
     insertAtHead(n,2);
     display(n);
     insertAtTail(n,3);
     display(n);
     insertAtPosition(n,4,2);
     display(n);
     deleteAtHead(n);
     display(n);
     deleteAtTail(n);
     display(n);
     deleteAtPosition(n,0);
     display(n);
     return 0;
 }
