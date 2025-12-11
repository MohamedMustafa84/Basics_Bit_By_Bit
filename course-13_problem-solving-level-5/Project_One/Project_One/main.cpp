#include <iostream>
#include "ClsDblLinkedList.h"
using namespace std;



int main(){

    clsDblLinkedList<int> MyDblLinkedList;

    // MyDblLinkedList.InsertAtBeginning(6);
    // MyDblLinkedList.InsertAtBeginning(4);
    // MyDblLinkedList.InsertAtBeginning(500);
    // MyDblLinkedList.InsertAtBeginning(3);
    // MyDblLinkedList.InsertAtBeginning(2);
    // MyDblLinkedList.InsertAtBeginning(1);

    // cout << "Linked List Content : \n";
    // MyDblLinkedList.printList();

    // int ValueToFind=500;

    // clsDblLinkedList<int>::node *NodeToFind = MyDblLinkedList.Find(ValueToFind);

    // if(NodeToFind !=NULL){
    //     cout << "\nNode with the Value " << ValueToFind << " is Found :-) " << endl;
    // }else{
    //     cout << "\nNode is Not Found " << endl;
    // }

    // cout <<"\n--------------------------------------------\n"; 

    // clsDblLinkedList<int>::node *NodeToInsertAfter = MyDblLinkedList.Find(4);
    // MyDblLinkedList.InsertAfter(NodeToInsertAfter, 5);
    // cout << "After Inserting 5  After 4 " << endl;
    // MyDblLinkedList.printList();
    
    // MyDblLinkedList.InsertAtEnd(7);
    // cout << "\n\nAfter Inserting 7 at the end of the list \n";
    // MyDblLinkedList.printList();

    // MyDblLinkedList.InsertAtBeginning(0);
    // cout << "\n\nAfter Inserting 0 at the Beginning of the list \n";
    // MyDblLinkedList.printList();

    // clsDblLinkedList<int>::node *NodeToBeDelete = MyDblLinkedList.Find(500);

    // MyDblLinkedList.DeleteNode(NodeToBeDelete);
    // cout << "\n\nAfter deleting the node of the value 500\n";
    // MyDblLinkedList.printList();

    // MyDblLinkedList.DeleteFirstNode();
    // cout << "\n\nAfter deleting the first node \n";
    // MyDblLinkedList.printList();
    // MyDblLinkedList.DeleteLastNode();
    // cout << "\n\nAfter deleting the Last node \n";
    // MyDblLinkedList.printList();

    
    
    
    // Extention 1 : Add size Method

    MyDblLinkedList.InsertAtBeginning(5);
    MyDblLinkedList.InsertAtBeginning(4);
    MyDblLinkedList.InsertAtBeginning(3);
    MyDblLinkedList.InsertAtBeginning(2);
    MyDblLinkedList.InsertAtBeginning(1);

    cout << "Linked List Content :\n";
    MyDblLinkedList.printList();

    cout << "\n the number of items in the linked list  = " << MyDblLinkedList.Size();

    return 0;
}
