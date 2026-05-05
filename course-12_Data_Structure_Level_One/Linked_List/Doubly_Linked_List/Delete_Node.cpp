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



node *FindNode(node *head, int NodeValue)
{

    while (head != NULL)
    {

        if (head->value == NodeValue)
        {
            return head;
        }

        head = head->next;
    }

    return NULL;
}

void DeleteNode(node *&head, node *& NodeToDelete ){

    if (head == NULL || NodeToDelete==NULL){
        return;
    }

    if(head == NodeToDelete){
        head = NodeToDelete->next;
    }

    if(NodeToDelete->next !=NULL){
        NodeToDelete->next->prev = NodeToDelete->prev;
    }

    if(NodeToDelete->prev !=NULL){
        NodeToDelete->prev->next = NodeToDelete->next;
    }

    delete NodeToDelete;
}

int main()
{
    node *head = NULL;

    InsertAtBegining(head, 1);
    InsertAtBegining(head, 2);
    InsertAtBegining(head, 3);
    InsertAtBegining(head, 500);
    InsertAtBegining(head, 4);
    InsertAtBegining(head, 5);

    cout << "The Double Linked List Elements :\n";
    printList(head);

    int NodeToBeDeleteValue = 500;

    node *NodeToBeDelete = FindNode(head, NodeToBeDeleteValue);

    DeleteNode(head, NodeToBeDelete);
    cout << "\nLinked List After Deleting the Node :\n";
    printList(head);

    return 0;
}