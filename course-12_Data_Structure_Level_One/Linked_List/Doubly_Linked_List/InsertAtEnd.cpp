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

void InsertAtEnd(node *&head, int value)
{

    node *newNode = new node();

    newNode->value = value;
    newNode->next = NULL;
    
    if(head ==NULL){
        
        newNode->prev = NULL; 
        head = newNode;
        
    }else{

        node *Current=head;

        while(Current->next !=NULL){
    
            Current = Current->next;
        }

        Current->next = newNode;
        newNode->prev = Current;
    }

}




int main()
{
    node *head = NULL;

    InsertAtEnd(head, 1);
    InsertAtEnd(head, 2);
    InsertAtEnd(head, 3);
    InsertAtEnd(head, 4);
    InsertAtEnd(head, 5);

    cout << "The Double Linked List Elements :\n";
    printList(head);




    return 0;
}