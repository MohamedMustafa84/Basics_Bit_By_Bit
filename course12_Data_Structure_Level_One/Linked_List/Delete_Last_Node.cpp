#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node *Next;
};

void InsertAtEnd(node *&head, int value)
{
    node *newNode = new node();

    newNode->value = value;
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
        cout << head->value << " ";
        head = head->Next;
    }
}

void DeleteLastNode(node *&head)
{
    node *Current = head;
    node *Prev = head;

    if (head == NULL)
    {
        return;
    }

    if(Current->Next == NULL){
        head = NULL;
        delete Current;
        return;
    }

    while(Current !=NULL && Current->Next !=NULL){
        Prev = Current;
        Current= Current->Next;
    }

    Prev->Next = NULL;


    delete Current;

    return;
}

int main()
{

    node *head = NULL;

    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtEnd(head, 4);
    InsertAtEnd(head, 5);
    InsertAtEnd(head, 5);
    cout << "the list before deleting the last node :";
    printList(head);

    DeleteLastNode(head);

    cout << "\nthe list After deleting the last node :";
    printList(head);

    return 0;
}