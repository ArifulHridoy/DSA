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

class LinkedList
{
public :
    Node* head;

    LinkedList()
    {
        head = NULL;
    }
    void llinsert(int x)
    {
        Node* newNode = new Node(x);

        if(head==NULL)
        {
            head = newNode;
            return;
        }
        Node* temp = head;

        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display()
    {
        Node* temp = head;

        while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    }
};

void deleteAlternate(Node* &head)
{
    Node* cNode = head;
    while(cNode!=NULL && cNode->next!=NULL)
    {
       Node* tempo = cNode->next;
       cNode->next = cNode->next->next;
       free(tempo);
       cNode=cNode->next;
    }
}
 int main()
 {
     LinkedList l1;
     l1.llinsert(1);
     l1.llinsert(9);
     l1.llinsert(6);
     l1.llinsert(5);
     l1.llinsert(1);
     l1.llinsert(9);
     l1.llinsert(3);
     l1.llinsert(5);
     l1.display();
     deleteAlternate(l1.head);
     l1.display();
     return 0;
 }
