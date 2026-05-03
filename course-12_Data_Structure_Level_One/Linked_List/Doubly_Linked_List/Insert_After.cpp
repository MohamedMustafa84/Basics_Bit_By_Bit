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

void InsertAfter(node *& NodeToInsertAfter ,int value){

    node *newNode = new node();

    newNode->prev = NodeToInsertAfter;
    newNode->value = value;
    newNode->next = NodeToInsertAfter->next;

    if(NodeToInsertAfter !=NULL){
        NodeToInsertAfter->next->prev = newNode;
    }

    NodeToInsertAfter->next = newNode;
}


int main()
{
    node *head = NULL;

    InsertAtBegining(head, 1);
    InsertAtBegining(head, 2);
    InsertAtBegining(head, 3);
    InsertAtBegining(head, 4);
    InsertAtBegining(head, 5);

    cout << "The Double Linked List Elements :\n";
    printList(head);
    
    
    node *NodeToInsertAfter = FindNode(head, 3);
    
    InsertAfter(NodeToInsertAfter, 500);
    cout << "\nLinked List After Adding the New Node :\n";
    printList(head);

    return 0;
}