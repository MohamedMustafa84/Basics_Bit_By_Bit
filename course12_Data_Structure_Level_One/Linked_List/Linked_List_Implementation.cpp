#include <iostream>
using namespace std;

class Node{
    public :
        int value;
        Node *Next;
};


int main(){

    Node *head =NULL;

    Node *Node1 = NULL;
    Node *Node2 = NULL;
    Node *Node3 = NULL;

// allocate three nodes in the heap
    Node1 = new Node();
    Node2 = new Node();
    Node3 = new Node();

    // asign value values
    Node1->value = 10;
    Node2->value = 20;
    Node3->value = 30;

// connect nodes
    Node1->Next = Node2;
    Node2->Next = Node3;
    Node3->Next = NULL; 


    
    cout << "the Linked List Content Is : " << endl;
    //point the linked list value 
    head=Node1;

    while(head !=NULL){
        cout << head->value << endl;

        head = head->Next;
    }

    return 0;
}