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

node *FindNode(node * head ,int NodeValue){


    while(head !=NULL){

        if(head->value == NodeValue){
            return head;
        }

        head = head->next;
    }

    return NULL;
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

    int NodeValue =10;

    cout << "\nIs Node With Value " <<NodeValue << " Exist ? \n";

    cout << (FindNode(head,NodeValue) ? " Yes The Node Exist " : "No This Node Is Not Exist ") << endl;

    return 0;
}