#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node *Next;
};

void InsertAtEnd(node* &head,int value){
    node *newNode=new node();

    newNode->value = value;
    newNode->Next = NULL;

    if(head==NULL){
        head = newNode;
        return;
    }


    // search for the last node 
    node *lastNode = head;

    while (lastNode->Next != NULL)
    {
        lastNode = lastNode->Next;
    }

    lastNode->Next = newNode;
    return;
}

void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->Next;
    }
}

int main()
{

    node *head = NULL;

    InsertAtEnd(head, 10);
    InsertAtEnd(head, 20);
    InsertAtEnd(head, 30);
    InsertAtEnd(head, 40);


    cout << "the linked list items are :  " << endl;
    printList(head);

    return 0;
}