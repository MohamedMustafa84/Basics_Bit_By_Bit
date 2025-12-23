# include <iostream>
#include "ClsDynamicArray.h"
using namespace std;


int main(){

    clsDynamicArray<int> MyDynamicArray(5);

    MyDynamicArray.SetItem(0, 10);
    MyDynamicArray.SetItem(1, 20);
    MyDynamicArray.SetItem(2, 30);
    MyDynamicArray.SetItem(3, 40);
    MyDynamicArray.SetItem(4, 50);

    cout << "\nIs Empty ? " <<( MyDynamicArray.IsEmpty()? "YES" :"No");
    cout << "\nArray Size : " << MyDynamicArray.Size();

    cout << "\n Array Items : \n";
    MyDynamicArray.printList();

    // Extention 1 Resize Array
    MyDynamicArray.Resize(2);
    cout << "\n\nArray Size : " << MyDynamicArray.Size();
    cout << "\nArray Items After Resize To 2 : \n";
    MyDynamicArray.printList();

    MyDynamicArray.Resize(5);
    MyDynamicArray.SetItem(2, 30);
    MyDynamicArray.SetItem(3, 40);
    MyDynamicArray.SetItem(4, 50);
    cout << "\n\nArray Size : " << MyDynamicArray.Size();
    cout << "\nArray Items After Resize To 5 : \n";
    MyDynamicArray.printList();

    // Extention 2  Get Item

    cout << "\n Item of the Index 2 Is : " << MyDynamicArray.GetItem(2);

    //Extention 3 Reverse the Array
    
    MyDynamicArray.Reverse();
    
    cout << "\nArray Items After Reverse :\n";
    MyDynamicArray.printList();
    
    
    //Extention 4 Clear The Array
    
    MyDynamicArray.Clear();
    cout << "Array After Clear  :" << endl;
    MyDynamicArray.printList();
    
    //Extention 5 Delete items At Index
    clsDynamicArray<int> MyDynamicArray2(5);
    MyDynamicArray2.SetItem(0, 10);
    MyDynamicArray2.SetItem(1, 20);
    MyDynamicArray2.SetItem(2, 30);
    MyDynamicArray2.SetItem(3, 40);
    MyDynamicArray2.SetItem(4, 50);
    MyDynamicArray2.printList();

    MyDynamicArray2.DeleteItemAt(2);

    cout << "Array After Deleting Item At Index 2 : \n";
    MyDynamicArray2.printList();
    
    //Extention 6 Delete First Item
    
    MyDynamicArray2.DeleteFirstItem();
    cout << "Array after deleting the fist item : \n";
    MyDynamicArray2.printList();
    
    //Extention 7 Delete Last Item

    MyDynamicArray2.DeleteLastItem();
    cout << "Array after deleting the Last item : \n";
    MyDynamicArray2.printList();

    // Extention  8 Find the item index
    
    cout << "the index of 40 is  " << MyDynamicArray2.Find(40) << endl;
    
    // Extention  9 Delete Item By Value
    MyDynamicArray2.Deleteitem(40);

    cout << "the Array After Deleting 40 is :\n";
    MyDynamicArray2.printList();


    // Extention 10 Insert At Index 

    cout <<"\n---------- Insert At Specific Index ------------"<<endl;
    clsDynamicArray<int> MyDynamicArray3(5);

    MyDynamicArray3.SetItem(0, 10);
    MyDynamicArray3.SetItem(1, 20);
    MyDynamicArray3.SetItem(2, 40);
    MyDynamicArray3.SetItem(3, 50);
    MyDynamicArray3.SetItem(4, 60);
    
    MyDynamicArray3.printList();
    
    MyDynamicArray3.InsertAt(2,30);
    cout <<"Array After Adding Number 30 At Index 2 \n";
    MyDynamicArray3.printList();

    // Extention 11 Insert At Beginning
    
    MyDynamicArray3.InsertAtBeginning(0);
    
    cout <<"Array After Insert Zero At Beginning :\n";
    MyDynamicArray3.printList();
    
    
    
// Extention 12 Insert Before specific Item

MyDynamicArray3.InsertBefore(30,300);

    cout<<"Array After Inserting 300 Before 30 :\n";
    MyDynamicArray3.printList();
    
    
    // Extention 13 Insert At The End 
    MyDynamicArray3.InsertAtEnd(70);

    cout <<"Array After Inserting 70 At The End :\n";
    MyDynamicArray3.printList();


    // Extention 14 Insert After specific Item

    MyDynamicArray3.InsertAfter(40,400);

    cout<<"Array After Inserting 400 After 40 :\n";
    MyDynamicArray3.printList();

    return 0;
}   