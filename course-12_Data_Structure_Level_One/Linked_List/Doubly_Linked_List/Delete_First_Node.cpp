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


void DeleteFirstNode(node *&head)
{

    if (head == NULL)
    {
        return;
    }

    node *temp = head;

    head = head->next;

    if(head!=NULL){
        head->prev = NULL;
    }

    delete temp;
}

int main()
{
    node *head = NULL;

    InsertAtBegining(head, 5);
    InsertAtBegining(head, 4);
    InsertAtBegining(head, 3);
    InsertAtBegining(head, 2);
    InsertAtBegining(head, 1);
    InsertAtBegining(head, 1);

    cout << "The Double Linked List Elements :\n";
    printList(head);



    DeleteFirstNode(head);
    cout << "\nLinked List After Deleting the First Node :\n";
    printList(head);

    return 0;
}