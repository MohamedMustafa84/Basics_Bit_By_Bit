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

void InsertAtBegining(node * & head, int value){

    node *newNode = new node();

    newNode->value = value;
    newNode->next = head;
    newNode->prev = NULL;

    if(head!=NULL){
        head->prev = newNode;
    }

    head = newNode;
}

void printNodeDetails(node *head){
    while(head !=NULL){
        cout << head->prev << " <--> " << head->value << " <--> " << head->next << endl;
        head = head->next;
    }
}

int main(){
    node *head = NULL;

    InsertAtBegining(head, 1);
    InsertAtBegining(head, 2);
    InsertAtBegining(head, 3);
    InsertAtBegining(head, 4);
    InsertAtBegining(head, 5);

    cout << "The Double Linked List Elements :\n";
    printList(head);

    printNodeDetails(head);
    return 0;
}