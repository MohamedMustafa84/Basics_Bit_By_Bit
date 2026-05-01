#include <iostream>
using namespace std;


class node{
    public :
        int value;
        node *Next;
};


void InsertAtBeginning(node* & head, int value){
    node *newNode=new node();

    newNode->value = value;
    newNode->Next = head;

    head = newNode;
}

void printList(node *head){
    while(head !=NULL){
        cout << head->value <<" ";
        head = head->Next;
    }
}



int main(){

    node *head=NULL;

    InsertAtBeginning(head, 10);
    InsertAtBeginning(head, 20);
    InsertAtBeginning(head, 30);
    InsertAtBeginning(head, 40);

    cout << "the linked list items are :  "<<endl;
    printList(head);

    return 0;
}