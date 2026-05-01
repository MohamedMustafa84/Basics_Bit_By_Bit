#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node *Next;
};

void InsertAtBeginning(node *&head, int value)
{
    node *newNode = new node();

    newNode->value = value;
    newNode->Next = head;

    head = newNode;
}

node *Find(node *head, int value){
    while(head !=NULL){
        if(head->value == value){
            return head;
        }
        head = head->Next;
    }
    return NULL;
}

    int main()
{

    node *head = NULL;

    InsertAtBeginning(head, 10);
    InsertAtBeginning(head, 20);
    InsertAtBeginning(head, 30);
    InsertAtBeginning(head, 40);

    


    // Find Node

    cout << ((Find(head, 20) != NULL )? "the node is found " : "the node is not found ") << endl;

    return 0;
}