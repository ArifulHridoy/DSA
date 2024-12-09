// ARIFUL_HRIDOY
// 2207051
// At first create a structure CT_mark.
// It will have two values – roll, mark.
// You will insert these values in the linked list.
// Your linked list should be sorted  by marks after each insertion.
// If two students get same mark, student with smaller roll should be come first in the list.

#include<iostream>
using namespace std;

struct CT
{
    int roll;
    int mark;
};

struct Node
{
    CT data;
    Node* next;
    Node(CT d)
    {
        data = d;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head=NULL;
    }
    void sortInsert(CT student)
    {
        Node* newNode = new Node(student);

        if(head==NULL || head->data.mark > student.mark || (head->data.mark == student.mark && head->data.roll > student.roll))
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;

        while(temp->next!=NULL && (temp->next->data.mark < student.mark || (temp->next->data.mark == student.mark && temp->next->data.roll < student.roll)))
              {
                  temp=temp->next;
              }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    void display()
    {
        Node* temp = head;
        while(temp!=NULL)
        {
            cout<<"Roll : "<<temp->data.roll<<"\t"<<"Mark : "<<temp->data.mark<<endl;
            temp = temp->next;
        }
    }
};
int main()
{
    LinkedList ll;
    ll.sortInsert({1,90});
    ll.sortInsert({2,80});
    ll.sortInsert({3,91});
    ll.sortInsert({4,79});
    ll.sortInsert({5,92});
    ll.sortInsert({6,85});
    ll.display();
}
