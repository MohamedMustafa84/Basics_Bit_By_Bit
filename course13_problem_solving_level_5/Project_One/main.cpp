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

    // ---------------------------------------------------------------------------------------------------

    // Extention 1 : Add size Method
    
    // MyDblLinkedList.InsertAtBeginning(5);
    // MyDblLinkedList.InsertAtBeginning(4);
    // MyDblLinkedList.InsertAtBeginning(3);
    // MyDblLinkedList.InsertAtBeginning(2);
    // MyDblLinkedList.InsertAtBeginning(1);
    
    // cout << "Linked List Content :\n";
    // MyDblLinkedList.printList();
    
    // cout << "\n the number of items in the linked list  = " << MyDblLinkedList.Size();

    // ---------------------------------------------------------------------------------------------------

    // Extention 2 : Add method To Check If The linked List Empty
    
    // cout << "is the linked list Empty ? \n";
    
    // cout << (MyDblLinkedList.IsEmpty()? "Yes List is Empty \n" : "No List is Not Empty \n");
    
    // MyDblLinkedList.InsertAtBeginning(3);
    // MyDblLinkedList.InsertAtBeginning(2);
    // MyDblLinkedList.InsertAtBeginning(1);
    // cout << "\nAfter Adding Some Element  is it still empty ? \n" << endl;
    // cout << (MyDblLinkedList.IsEmpty()? "Yes List is Empty \n" : "No List is Not Empty \n");

    // ---------------------------------------------------------------------------------------------------

    // Extention 3 : Clear the linked list
    
    // MyDblLinkedList.InsertAtBeginning(3);
    // MyDblLinkedList.InsertAtBeginning(2);
    // MyDblLinkedList.InsertAtBeginning(1);

    // cout << "Linked list content :\n";
    // MyDblLinkedList.printList();
    
    // cout << "Number of Items in the linked list is " << MyDblLinkedList.Size();
    
    // cout << "\nExecuting Clear()\n";
    // MyDblLinkedList.Clear();
    
    // MyDblLinkedList.printList();
    // cout << "Number of Items in the linked list is " << MyDblLinkedList.Size();

    // ---------------------------------------------------------------------------------------------------

    // Extention 4 : Reverse the linked list
    
    // MyDblLinkedList.InsertAtBeginning(5);
    // MyDblLinkedList.InsertAtBeginning(4);
    // MyDblLinkedList.InsertAtBeginning(3);
    // MyDblLinkedList.InsertAtBeginning(2);
    // MyDblLinkedList.InsertAtBeginning(1);

    // cout <<"Linked List Content :\n";
    // MyDblLinkedList.printList();

    // MyDblLinkedList.Reverse();

    // cout << "\n The linked list After the Reverse :\n";
    // MyDblLinkedList.printList();

    // ---------------------------------------------------------------------------------------------------

    // Extention 5 : Get Node By Index

    // MyDblLinkedList.InsertAtBeginning(5);
    // MyDblLinkedList.InsertAtBeginning(4);
    // MyDblLinkedList.InsertAtBeginning(3);
    // MyDblLinkedList.InsertAtBeginning(2);
    // MyDblLinkedList.InsertAtBeginning(1);

    // cout <<"Linked List Content :\n";
    // MyDblLinkedList.printList();

    // clsDblLinkedList<int>::node *NodeToFind;

    // NodeToFind = MyDblLinkedList.GetNode(3);

    // cout << "the node at the index 3 is " << NodeToFind->value << endl;

    // ---------------------------------------------------------------------------------------------------
    // Extention 6 : Get Item By Index

    // MyDblLinkedList.InsertAtBeginning(5);
    // MyDblLinkedList.InsertAtBeginning(4);
    // MyDblLinkedList.InsertAtBeginning(3);
    // MyDblLinkedList.InsertAtBeginning(2);
    // MyDblLinkedList.InsertAtBeginning(1);

    // cout <<"Linked List Content :\n";
    // MyDblLinkedList.printList();

    // cout << "Item 2 value is " << MyDblLinkedList.GetItem(2) << endl;



    // ---------------------------------------------------------------------------------------------------

    // Extention 7 : Update Item By Index

    // MyDblLinkedList.InsertAtBeginning(5);
    // MyDblLinkedList.InsertAtBeginning(4);
    // MyDblLinkedList.InsertAtBeginning(500);
    // MyDblLinkedList.InsertAtBeginning(2);
    // MyDblLinkedList.InsertAtBeginning(1);

    // cout <<"Linked List Content :\n";
    // MyDblLinkedList.printList();

    // MyDblLinkedList.Update(2, 3);

    // cout <<"Linked List After Updating the item of the Index 2  " <<endl;
    // MyDblLinkedList.printList();


    
    // ---------------------------------------------------------------------------------------------------

    // Extention 8 : Insert After node By Index  

    MyDblLinkedList.InsertAtBeginning(5);
    MyDblLinkedList.InsertAtBeginning(4);
    MyDblLinkedList.InsertAtBeginning(500);
    MyDblLinkedList.InsertAtBeginning(2);
    MyDblLinkedList.InsertAtBeginning(1);

    cout <<"Linked List Content :\n";
    MyDblLinkedList.printList();

    MyDblLinkedList.InsertAfter(2, 3);

    cout <<"Linked List After Updating the item of the Index 2  " <<endl;
    MyDblLinkedList.printList();






    return 0;
}
