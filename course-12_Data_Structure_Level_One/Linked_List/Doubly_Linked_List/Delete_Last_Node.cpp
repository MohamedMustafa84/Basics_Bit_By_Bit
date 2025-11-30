#include <iostream>
using namespace std;

class node
{
public:
    node *prev;
    int value;
    node *next;
};

void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
}

void InsertAtBegining(node *&head, int value)
{

    node *newNode = new node();

    newNode->value = value;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}

void DeleteLastNode(node *&head)
{

    if (head == NULL)
    {
        return;
    }

    if(head->next ==NULL){
        delete head;
        head = NULL;
        return;
    }


    // we need to find the node before last node

    node *Current = head;

    while(Current->next->next !=NULL){
        Current = Current->next;
    }

    node *temp = Current->next;
    Current->next = NULL;

    delete temp;
}

int main()
{
    node *head = NULL;

    InsertAtBegining(head, 5);
    InsertAtBegining(head, 5);
    InsertAtBegining(head, 4);
    InsertAtBegining(head, 3);
    InsertAtBegining(head, 2);
    InsertAtBegining(head, 1);

    cout << "The Double Linked List Elements :\n";
    printList(head);

    DeleteLastNode(head);
    cout << "\nLinked List After Deleting the Last Node :\n";
    printList(head);

    return 0;
}