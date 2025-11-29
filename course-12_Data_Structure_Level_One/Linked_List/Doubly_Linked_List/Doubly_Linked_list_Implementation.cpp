#include <iostream>
using namespace std;


class node {
    public :
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

int main(){
    
    node *head=NULL;

    node *node1 = NULL;
    node *node2 = NULL;
    node *node3 = NULL;

    node1 = new node();
    node2 = new node();
    node3 = new node();

    node1->value = 10;
    node2->value = 20;
    node3->value = 30;

    node1->prev = NULL;
    node2->prev = node1;
    node3->prev = node2;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    printList(head);

    return 0;
}