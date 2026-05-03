#include <iostream>
using namespace std ;




class node{
    public :
        int Value;
        node *Next;
};

void InsertAtEnd(node *&head, int value)
{
    node *newNode = new node();

    newNode->Value = value;
    newNode->Next = NULL;

    if (head == NULL)
    {
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
        cout << head->Value << " ";
        head = head->Next;
    }
}

void DeleteNode(node *head,int value){

    if(head ==NULL){
        return;
    }

    node *Current=head;
    node *Prev=head;

    if(Current->Value == value){
        head = Current->Next;
        // Delete Node 
        delete Current;
    }


    // Find the Key To Be Deleted 
    while(Current !=NULL && Current->Value != value){
        Prev = Current;
        Current = Current->Next;
    }

    // if the value is not present
    if(Current==NULL)
        return;

    Prev->Next = Current->Next;
    delete Current;//free from memory
}


int main(){

    node *head = NULL;

    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtEnd(head, 4);
    InsertAtEnd(head, 5);

    cout << "Before the delete : ";
    printList(head);
    
    DeleteNode(head, 2);
    cout << "\nAfter the delete : ";
    printList(head);

    return 0;
}